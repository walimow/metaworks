//
// Created by karsten on 25.12.20.
//

#ifndef METAWORKS_NAMESQ_HPP
#define METAWORKS_NAMESQ_HPP

#include <array>
#include <tuple>
#include <typeinfo>

namespace metaworks {

    namespace detail {

        template<typename ...>
        struct count_of_args;

        template<typename Ty>
        struct count_of_args<Ty> {
            static const std::size_t value = 1;
        };

        template<typename Ty, typename ...Args>
        struct count_of_args<Ty, Args...> {
            static const std::size_t value = 1 + count_of_args<Args...>::value;
        };

        template<unsigned int, typename...>
        struct _setcax_;

        template<unsigned int X, typename Ty, typename ...Args>
        struct _setcax_<X, Ty, Args...> {
            static auto act(const char *dest[]) {
                dest[X] = typeid(Ty).name();
                return _setcax_<X + 1, Args...>::act(dest);
            }
        };

        template<unsigned int X, typename Ty>
        struct _setcax_<X, Ty> {
            static auto act(const char *dest[]) {
                dest[X] = typeid(Ty).name();
                return dest;
            }
        };

    }

    template<typename  ...Args>
    constexpr auto nm_sq() {
        std::array<char *, detail::count_of_args<Args...>::value> arr;
        detail::_setcax_<0, Args...>::act((const char **) &arr);
        return arr;
    }

}


#endif //METAWORKS_NAMESQ_HPP
