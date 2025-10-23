#include <array>
#include <chrono>
namespace compunits
{
    constexpr size_t operator"" _KB(unsigned long long const size)
    {
        return static_cast<size_t>(size * 1024);
    }
}

namespace units
{
    enum class unit
    {
        kilogram,
        liter,
        meter,
        piece,
    };

    template <unit U>
    class quantity
    {
        const double amount;

    public:
        constexpr explicit quantity(double const a) : amount(a)
        {
        }
        explicit operator double() const { return amount; }
    };

    template <unit U>
    constexpr quantity<U> operator+(quantity<U> const &q1,
                                    quantity<U> const &q2)
    {
        return quantity<U>(static_cast<double>(q1) + static_cast<double>(q2));
    }
    template <unit U>
    constexpr quantity<U> operator-(quantity<U> const &q1,
                                    quantity<U> const &q2)
    {
        return quantity<U>(static_cast<double>(q1) - static_cast<double>(q2));
    }

    namespace unit_literals
    {
        constexpr quantity<unit::kilogram> operator"" _kg(
            long double const amount)
        {
            return quantity<unit::kilogram>{static_cast<double>(amount)};
        }
        constexpr quantity<unit::kilogram> operator"" _kg(
            unsigned long long const amount)
        {
            return quantity<unit::kilogram>{static_cast<double>(amount)};
        }
        constexpr quantity<unit::liter> operator"" _l(
            long double const amount)
        {
            return quantity<unit::liter>{static_cast<double>(amount)};
        }
        constexpr quantity<unit::meter> operator"" _m(
            long double const amount)
        {
            return quantity<unit::meter>{static_cast<double>(amount)};
        }
        constexpr quantity<unit::piece> operator"" _pcs(
            unsigned long long const amount)
        {
            return quantity<unit::piece>{static_cast<double>(amount)};
        }
    }
}

int main()
{
    using namespace compunits;
    auto size{4_KB}; // size_t size = 4096;
    using byte = unsigned char;
    auto buffer = std::array<byte, 1_KB>{};

    using namespace std::chrono_literals;
    // std::chrono::duration<long long>
    auto timer{2h + 42min + 15s};

    using namespace units;
    using namespace unit_literals;

    auto q1{1_kg};    // OK
    auto q2{4.5_kg};  // OK
    auto q3{q1 + q2}; // OK
    auto q4{q2 - q1}; // OK
    // error, cannot add meters and pieces
    auto q5{1.0_m + 1_pcs};
    // error, cannot have an integer number of liters
    auto q6{1_l};
    // error, can only have an integer number of pieces
    auto q7 { 2.0_pcs };
}
