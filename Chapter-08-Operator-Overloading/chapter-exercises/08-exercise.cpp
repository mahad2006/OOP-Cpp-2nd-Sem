#include <bits/stdc++.h>
using namespace std;
class bMoney
{
    long long cents_; // internal representation: total cents
    static long long parseToCents(const string &s)
    {
        // Accepts formats like "$123.45", "123.45", "-$123.45", "(123.45)"
        string t;
        for (char c : s)
            if (!isspace((unsigned char)c))
                t.push_back(c);
        if (t.empty())
            throw invalid_argument("Empty money string");

        bool negative = false;
        if (t.front() == '(' && t.back() == ')')
        {
            negative = true;
            t = t.substr(1, t.size() - 2);
        }
        else if (t.front() == '-')
        {
            negative = true;
            t = t.substr(1);
        }

        // remove leading $
        if (!t.empty() && t.front() == '$')
            t = t.substr(1);

        // remove commas
        t.erase(remove(t.begin(), t.end(), ','), t.end());

        // find decimal point
        size_t pos = t.find('.');
        string dollars = (pos == string::npos) ? t : t.substr(0, pos);
        string cents_str = (pos == string::npos) ? string() : t.substr(pos + 1);

        if (dollars.empty())
            dollars = "0";
        if (!all_of(dollars.begin(), dollars.end(), ::isdigit))
            throw invalid_argument("Bad money format (dollars)");
        if (!cents_str.empty() && !all_of(cents_str.begin(), cents_str.end(), ::isdigit))
            throw invalid_argument("Bad money format (cents)");

        long long d = stoll(dollars);
        // Normalize cents_str to exactly 2 digits, rounding if necessary
        long double cent_value = 0.0L;
        if (cents_str.empty())
        {
            cent_value = 0.0L;
        }
        else if (cents_str.size() == 1)
        {
            cent_value = (cents_str[0] - '0') * 10.0L;
        }
        else
        {
            // take more than 2 digits into account for rounding
            string firstTwo = cents_str.substr(0, 2);
            string rest = (cents_str.size() > 2) ? cents_str.substr(2) : "";
            long double centPart = stoll(firstTwo);
            long double roundingDigit = 0;
            if (!rest.empty())
                roundingDigit = rest[0] - '0';
            // simple rounding: if roundingDigit >=5, add 1
            if (roundingDigit >= 5)
                centPart += 1;
            if (centPart >= 100)
            {
                d += 1;
                centPart -= 100;
            }
            cent_value = centPart;
        }

        long long totalCents = d * 100 + static_cast<long long>(llround(cent_value));
        if (negative)
            totalCents = -totalCents;
        return totalCents;
    }

public:
    bMoney() : cents_(0) {}
    explicit bMoney(long double dollars) : cents_(llround(dollars * 100.0L)) {}
    explicit bMoney(const string &s) : cents_(parseToCents(s)) {}

    static bMoney fromCents(long long c)
    {
        bMoney m;
        m.cents_ = c;
        return m;
    }

    string toString() const
    {
        long long c = cents_;
        bool neg = (c < 0);
        if (neg)
            c = -c;
        long long dollars = c / 100;
        int cents = static_cast<int>(c % 100);
        ostringstream oss;
        if (neg)
            oss << '-';
        oss << '$' << dollars << '.' << setw(2) << setfill('0') << cents;
        return oss.str();
    }

    long double toDouble() const { return static_cast<long double>(cents_) / 100.0L; }

    // addition and subtraction
    bMoney operator+(const bMoney &other) const
    {
        return fromCents(cents_ + other.cents_);
    }
    bMoney operator-(const bMoney &other) const
    {
        return fromCents(cents_ - other.cents_);
    }
    bMoney &operator+=(const bMoney &other)
    {
        cents_ += other.cents_;
        return *this;
    }
    bMoney &operator-=(const bMoney &other)
    {
        cents_ -= other.cents_;
        return *this;
    }

    // multiply by scalar
    bMoney operator*(long double n) const
    {
        long double resCents = static_cast<long double>(cents_) * n;
        return fromCents(llround(resCents));
    }

    // divide by scalar -> bMoney
    bMoney operator/(long double n) const
    {
        if (n == 0.0L)
            throw invalid_argument("Divide by zero");
        long double resCents = static_cast<long double>(cents_) / n;
        return fromCents(llround(resCents));
    }

    // divide money by money -> long double
    long double operator/(const bMoney &other) const
    {
        if (other.cents_ == 0)
            throw invalid_argument("Divide by zero");
        return static_cast<long double>(cents_) / static_cast<long double>(other.cents_);
    }

    friend ostream &operator<<(ostream &os, const bMoney &m)
    {
        os << m.toString();
        return os;
    }
};

int main()
{
    cout << "Enter two money strings (e.g. $12.34) and a floating number (widgets). Type q to quit.\n";
    while (true)
    {
        string s1;
        cout << "\nEnter money #1 (or q to quit): ";
        if (!(cin >> s1))
            break;
        if (s1 == "q" || s1 == "Q")
            break;

        string s2;
        cout << "Enter money #2: ";
        if (!(cin >> s2))
            break;

        long double n;
        cout << "Enter a floating number (e.g. number of widgets): ";
        if (!(cin >> n))
            break;

        try
        {
            bMoney m1(s1), m2(s2);
            cout << "m1 = " << m1 << "   m2 = " << m2 << "\n";

            auto sum = m1 + m2;
            auto diff = m1 - m2;
            auto product = m2 * n;       // price per widget * count
            long double ratio = m1 / m2; // money / money -> number
            auto pricePer = m1 / n;      // money / count -> price (bMoney)

            cout << "m1 + m2 = " << sum << "\n";
            cout << "m1 - m2 = " << diff << "\n";
            cout << "m2 * n  = " << product << "\n";
            cout << "m1 / m2 = " << ratio << " (units)\n";
            cout << "m1 / n  = " << pricePer << "\n";
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << "\n";
        }

        // clear any leftover newline
        cin.clear();
    }

    cout << "Goodbye.\n";
    return 0;
}
