#include "gtest/gtest.h"
#include <metaworks.hpp>
#include <apply.hpp>

using metaworks::kind::get_kind_sz;
using metaworks::kind::ekind;


struct stri0 {
    int inner_value;
};

template<typename Ty>
struct str_ty {
    Ty inner_value;
};

TEST (mw_test_case, atom_0) {

    auto sz_a = get_kind_sz(42);
    EXPECT_EQ(sz_a, 1);

    auto ea = ekind(42);
    EXPECT_EQ(ea, metaworks::kind::atom);

}

TEST (mw_test_case, atom_s) {
    stri0 s0;

    auto sz_a = get_kind_sz(s0);
    EXPECT_EQ(sz_a, 1);

    auto ea = ekind(s0);
    EXPECT_EQ(ea, metaworks::kind::atom);

}


TEST (mw_test_case, atom_s42) {
    str_ty<int> s42{
            42
    };

    auto sz_a = get_kind_sz(s42);
    EXPECT_EQ(sz_a, 2);

    auto ea = ekind(s42);
    EXPECT_EQ(ea, metaworks::kind::form);

}


TEST (mw_test_case, atom_s422) {
    str_ty<str_ty<int>> s42{
            str_ty<int>{
                    42
            }
    };

    auto sz_a = get_kind_sz(s42);
    EXPECT_EQ(sz_a, 3);

    auto ea = ekind(s42);
    EXPECT_EQ(ea, metaworks::kind::mform);

}