import std;

// A single worker function reused for both demo sections.
// std::stop_token is passed automatically by jthread when the function
// signature accepts it as the first parameter.
void worker(std::stop_token token, int id, int interval_ms)
{
    int count = 0;
    while (!token.stop_requested())
    {
        std::println("Worker {} tick {}", id, ++count);
        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }
    std::println("Worker {} stopping", id);
    // std::stop_callback can be registered on a stop_token to run cleanup
    // logic (e.g. unblocking a condition_variable) when stop is requested.
}

int main()
{
    // --- 1. jthread with automatic stop + join ---
    // jthread destructor calls request_stop() then join() automatically,
    // so the thread always finishes cleanly when it goes out of scope.
    {
        std::jthread w(worker, 0, 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        w.request_stop(); // cooperative cancellation (optional: destructor does this too)
    } // w is joined here

    // --- 2. stop_source: stop multiple jthreads with one signal ---
    // Threads a and b share a token from the same stop_source.
    std::stop_source source;
    std::jthread     a(worker, source.get_token(), 1, 80);
    std::jthread     b(worker, source.get_token(), 2, 90);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    source.request_stop(); // both a and b see stop_requested() == true
    // a and b are joined automatically when they go out of scope
}
