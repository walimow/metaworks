#include <iostream>
#include <list>
#include "metaworks.hpp"
#include "kind.hpp"

#include <iostream>
#include <string>
#include <cassert>

#include "trace.hpp"

using metaworks::kind::get_kind_sz;

using metaworks::kind::trace_kind_f;

struct sa1 {
};

template<typename T>
struct st {
    T *st;
};

template<typename L, typename R>
struct st_lr {
    L *pL;
    R *pR;
};

template<typename L, typename R>
using st_1 = st_lr<L, R>;

#include <map>
#include <string>

template<typename Ty>
using smap = std::map<std::string, Ty>;

template<typename Ty>
using imap = std::map<int, Ty>;

int main() {
    sa1 a1;
    auto t11 = get_kind_sz(a1);

    //kin


    st<int> si2;
    auto t21 = get_kind_sz(si2);

    st<sa1> ssa2;
    auto t22 = get_kind_sz(ssa2);

    st<st<int>> sst3;
    auto t31 = get_kind_sz(sst3);

    st<st<st<int>>> sst4;
    auto t41 = get_kind_sz(sst4);

    std::cout << "a1: " << t11 << std::endl
              << "s2: " << t21 << std::endl
              << "ssa2: " << t22 << std::endl
              << "sst3: " << t31 << std::endl
              << "sst4: " << t41 << std::endl;

    //auto t1= kind



    smap<int> smi;

    auto tl3 = get_kind_sz(smi);
    std::cout << "smi/tl3: " << tl3 << std::endl;

    std::cout << "\n-----------smi:\n";
    trace_kind_f(smi);


    imap<int> imi;
    auto tl32 = get_kind_sz(imi);
    std::cout << "imi/tl32: " << tl32 << std::endl;

    std::cout << "\n-----------imi:\n";
    trace_kind_f(imi);


    auto l3 = get_kind_sz(sst3);
    std::cout << "\n-----------s3:\n" << l3 << std::endl;
    trace_kind_f(sst3);

    auto l4 = get_kind_sz(sst4);
    std::cout << "\n-----------s4:\n" << l4 << std::endl;
    trace_kind_f(sst4);


    std::cout << "\n-----------i:\n";
    trace_kind_f(42);

    //
    auto pa = std::make_pair(1, "Hallo");
    std::cout << "\n-----------pistr:\n" << get_kind_sz(pa) << "\n";
    trace_kind_f(pa);


    return 0;
}