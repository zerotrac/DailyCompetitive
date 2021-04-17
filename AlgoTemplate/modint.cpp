using namespace std;

using LL = long long;

template<int M>
class Modint {
private:
    static int quickmul(int x, int y) {
        int ret = 1, mul = x;
        while (y) {
            if (y & 1) {
                ret = (LL)ret * mul % M;
            }
            mul = (LL)mul * mul % M;
            y >>= 1;
        }
        return ret;
    }

public:
    Modint(): x_(0) {}
    Modint(int x): x_(x > 0 ? x % M : (x % M + M) % M) {}
    Modint(const Modint& that) { x_ = that.x_; }
    Modint(Modint&& that) { x_ = that.x_; }

    int get() const { return x_; }

    Modint neg() const { return -x_; }

    Modint& operator= (const Modint& that) { if (this != &that) x_ = that.x_; return *this; }
    Modint& operator= (Modint&& that) { if (this != &that) x_ = that.x_; return *this; }

    Modint& operator+= (const Modint& that) { x_ += that.x_; if (x_ >= M) x_ -= M; return *this; }
    Modint& operator-= (const Modint& that) { x_ -= that.x_; if (x_ < 0) x_ += M; return *this; }
    Modint& operator*= (const Modint& that) { x_ = (LL)x_ * that.x_ % M; return *this; }
    Modint& operator/= (const Modint& that) { x_ = (LL)x_ * quickmul(that.x_, M - 2) % M; return *this; }

    bool operator== (const Modint& that) const { return x_ == that.x_; }
    bool operator!= (const Modint& that) const { return x_ != that.x_; }
    bool operator< (const Modint& that) const { return x_ < that.x_; }
    bool operator> (const Modint& that) const { return x_ > that.x_; }

    template<int U>
    friend Modint<U> operator+ (const Modint<U>& u, const Modint<U>& v);
    template<int U>
    friend Modint<U> operator- (const Modint<U>& u, const Modint<U>& v);
    template<int U>
    friend Modint<U> operator* (const Modint<U>& u, const Modint<U>& v);
    template<int U>
    friend Modint<U> operator/ (const Modint<U>& u, const Modint<U>& v);

private:
    int x_;
};

template<int M>
Modint<M> operator+ (const Modint<M>& u, const Modint<M>& v) {
    int w = u.x_ + v.x_;
    if (w >= M) w -= M;
    return w;
}

template<int M>
Modint<M> operator- (const Modint<M>& u, const Modint<M>& v) {
    int w = u.x_ - v.x_;
    if (w < 0) w += M;
    return w;
}

template<int M>
Modint<M> operator* (const Modint<M>& u, const Modint<M>& v) {
    int w = (LL)u.x_ * v.x_ % M;
    return w;
}

template<int M>
Modint<M> operator/ (const Modint<M>& u, const Modint<M>& v) {
    int w = (LL)u.x_ * Modint<M>::quickmul(v.x_, M - 2) % M;
    return w;
}