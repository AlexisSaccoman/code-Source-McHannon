

class ThreadPool {
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();

    template <class F, class... Args>
    auto enqueue(F&& f, Args&&... args) -> future<typename result_of<F(Args...)>::type>;

private:
    // Workers
    vector<thread> workers;

    // Task queue
    queue<function<void()>> tasks;

    // Synchronization
    mutex queueMutex;
    condition_variable condition;
    bool stop;
};

// Implementation of the ThreadPool
ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this] {
            while (true) {
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(this->queueMutex);
                    this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });

                    if (this->stop && this->tasks.empty()) {
                        return;
                    }

                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                }

                task();
            }
        });
    }
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }

    condition.notify_all();

    for (std::thread& worker : workers) {
        worker.join();
    }
}

template <class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> result = task->get_future();

    {
        std::unique_lock<std::mutex> lock(queueMutex);
        if (stop) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }

        tasks.emplace([task]() { (*task)(); });
    }

    condition.notify_one();

    return result;
}




// solve helper function that recursively solves the puzzle
bool solve_parallel(const vector<Tile>& BoardInit, size_t numThreads) {
    vector<vector<Tile>> BoardSolvePartiel(BOARD_ROWS, vector<Tile>(BOARD_COLS));
    vector<Tile> BoardTileUsed = BoardInit;
    string borderColor = "";

    ThreadPool pool(numThreads);

    clock_t startTime = clock();

    vector<future<bool>> futures;
    // futures.reserve(BOARD_ROWS * BOARD_COLS);
    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLS; ++j) {
            futures.emplace_back(pool.enqueue([i, j, &BoardTileUsed, &BoardSolvePartiel, &borderColor] {
                return solve_sequential_helper(BoardTileUsed, BoardSolvePartiel, borderColor, i, j);
            }));
        }
    }

    bool solutionFound = all_of(futures.begin(), futures.end(), [](const future<bool>& f) { return f.get(); });
    // bool solutionFound = true;
    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    // cout << "Execution time: " << executionTime << endl;
    if (solutionFound) {
        Res = BoardSolvePartiel;
        fill_BoardRes_with_Res();
        display_board_color(BoardRes);
    } else {
        cout << "No solution found." << endl;
    }

    return solutionFound;
}
