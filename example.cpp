int Tick::some_method(some_params) {


}



class Tick {


    std::chrono::systemn_clock::time_point tick_time = std::chrono::sytem_lock::now();

    double ask_price;
    double bid_price;

    <some return type> friend  amendTick (Tick);
    Tick(stock s) {
        ask_price = s.<blah>;
        bid_price = s.<blah>;

    };

class Stock {

};

<some return type> amendTick(Tick T) {
    retrieves data and puts it into the T object
}

