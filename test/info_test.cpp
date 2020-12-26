//
// Created by kh on 24.12.20.
//

#include "gtest/gtest.h"
#include <info.hpp>
#include <namesq.hpp>
#include <eal/fo.hpp>

using metaworks::typeinfo::info;


TEST (mw_test_info, atom_kind) {

    auto katom = info<int>::kind_t();
    EXPECT_EQ(katom, metaworks::kind::atom);

}


namespace detail {

    template<typename Ty>
    struct echo {
        auto operator()(Ty &&a) const {
            return std::forward<Ty>(a);
        }
    };

    template<typename Ty>
    struct rcopy_echo {
        auto operator()(Ty a) const {
            return std::forward<Ty>(a);
        }
    };
}


using stepworks::eal::fo::mk_fo;
using stepworks::eal::fo::ft;

TEST (mw_test_info, fform_kind) {
    detail::rcopy_echo<int> fei;
    auto fofei = mk_fo(fei);  //ft<detail::echo<int> >
    using fofei_t = decltype(fofei);
    auto kfform = info<fofei_t>::kind_t();
    auto ikff = (int) kfform;
    std::cout << "\n===> " << ikff << " kff: " << ikff;
    EXPECT_EQ(kfform, metaworks::kind::fform);
}

#include <vector>

TEST (mw_test_info, mform_kind) {

    auto kmform = info<std::vector<char>>::kind_t();
    EXPECT_EQ(kmform, metaworks::kind::mform);
}


TEST (mw_test_info, mform_argsz) {

    auto sz1 = metaworks::detail::count_of_args<int>::value;
    EXPECT_EQ(sz1, 1);

    auto sz4 = metaworks::detail::count_of_args<int, char, char, int>::value;
    EXPECT_EQ(sz4, 4);
}


TEST (mw_test_info, mform_arg_nsq) {
    const auto vn = metaworks::nm_sq<int, char, double, double, long long>();
    for (const char *p : vn) {
        std::cout << p << "\n";
    }
    EXPECT_EQ(vn.size(), 5);
}


