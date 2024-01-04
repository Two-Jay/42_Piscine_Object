#include "Graph.hpp"
#include <limits>
#include "utils.hpp"
#include <iomanip>
#include "Label.hpp"

Graph::Graph() :
    _vecs(std::vector<Vector2>()),
    x_min(std::numeric_limits<float>::max()),
    x_max(std::numeric_limits<float>::min()),
    y_min(std::numeric_limits<float>::max()),
    y_max(std::numeric_limits<float>::min()) {

    }

Graph::Graph(std::vector<Vector2> &vecs) :
    _vecs(std::vector<Vector2>()),
    x_min(std::numeric_limits<float>::max()),
    x_max(std::numeric_limits<float>::min()),
    y_min(std::numeric_limits<float>::max()),
    y_max(std::numeric_limits<float>::min()) {
    for (std::vector<Vector2>::iterator it = vecs.begin(); it != vecs.end(); ++it) {
        this->add(*it);
    }
}

Graph::~Graph() {
    _vecs.clear();
}

void Graph::add(Vector2 &vec) {
    if (vec.getX() < x_min) {
        x_min = vec.getX();
    }
    if (vec.getX() > x_max) {
        x_max = vec.getX();
    }
    if (vec.getY() < y_min) {
        y_min = vec.getY();
    }
    if (vec.getY() > y_max) {
        y_max = vec.getY();
    }
    _vecs.push_back(vec);
}

void Graph::remove(Vector2 &vec) {
    for (std::vector<Vector2>::iterator it = _vecs.begin(); it != _vecs.end(); ++it) {
        if (*it == vec) {
            _vecs.erase(it);
            return;
        }
    }
}

#define DEFAULT_GRAPH_POINT '.'
#define DEFAULT_GRAPH_X_AXIS '-'
#define DEFAULT_GRAPH_Y_AXIS '|'
#define DEFAULT_GRAPH_ZERO '+'
#define DEFAULT_GRAPH_VECTOR 'x'

std::vector<std::vector<char> > Graph::generateGraph(Label &xl, Label &yl) const {
    std::vector<std::vector<char> > graph;
    long y_max = yl.getMax();
    long y_min = yl.getMin();
    long x_max = xl.getMax();
    long x_min = xl.getMin();

    for (long i = y_max; i >= y_min; i--) {
        std::vector<char> row;
        for (long j = x_min; j <= x_max; j++) {
            if (i == 0 && j == 0) {
                row.push_back(DEFAULT_GRAPH_ZERO);
            } else if (i == 0) {
                row.push_back(DEFAULT_GRAPH_X_AXIS);
            } else if (j == 0) {
                row.push_back(DEFAULT_GRAPH_Y_AXIS);
            } else {
                row.push_back(DEFAULT_GRAPH_POINT);
            }
        }
        graph.push_back(row);
    }
    return graph;
}

std::ostream &operator<<(std::ostream &o, Graph const &rhs) {
    long y_max = ft_roundf(rhs.y_max);
    long y_min = ft_roundf(rhs.y_min);
    long x_max = ft_roundf(rhs.x_max);
    long x_min = ft_roundf(rhs.x_min);
    Label yl = Label(y_min, y_max, 2);
    Label xl = Label(x_min, x_max, 1);
    o << "y max : " << y_max << ", y min : " << y_min << std::endl;
    o << "x max : " << x_max << ", x min : " << x_min << std::endl;
    std::vector<std::string>::reverse_iterator ylit = yl.rbegin();
    std::vector<std::string>::iterator xlit = xl.begin();
    std::vector<std::vector<char> > graph = rhs.generateGraph(xl, yl);
    for (int i = 0; i < static_cast<int>(graph.size()) + 1; i++) {
        o << *ylit;
        ylit++;
        if (i == static_cast<int>(graph.size())) {
            o << std::setw(yl.getPrintWidth()) << std::right << " ";
            for (int j = 0; j < static_cast<int>(graph[i - 1].size()); j++) {
                o << std::setw(xl.getPrintWidth()) << std::right << *xlit;
                xlit++; 
            }
        } else {
            for (int j = 0; j < static_cast<int>(graph[i].size()); j++) {
                o << std::setw(xl.getPrintWidth()) << std::right << graph[i][j];
            }
            o << std::endl;
        }
    }
    return o;
}

// 출력시 자간간격 팁
// 생각외로 세로 간격은 그렇게 큰 구애를 받지 않는다. 조정가능의 여지도 없다. 오히려 이 경우, 가로 간격이 더 중요하다.
// 가로 간격은 setw() 함수를 이용하여 조절할 수 있으며, iomanip 헤더를 include 하여 사용할 수 있다.
// 그래프 출력시 그래프 내용과 x축 라벨의 간격을 동일 인자를 기준으로 맞춰야 한다.
// 대강 생각하면 아래의 결론에 도달 가능하다.
//     - x축 라벨의 특정 지점의 값이 -100 ~ -999 사이라면 적어도 4자리 이상의 칸을 확보해야 한다.
//     - x축 라벨의 특정 지점의 값이 -10 ~ -99 사이라면 적어도 3자리 이상의 칸을 확보해야 한다.
//     - x축 라벨의 특정 지점의 값이 -1 ~ -9 사이라면 적어도 2자리 이상의 칸을 확보해야 한다.
//     - x축 라벨의 특정 지점의 값이 0 이라면 적어도 1자리 이상의 칸을 확보해야 한다.
//     - x축 라벨의 특정 지점의 값이 1 ~ 9 사이라면 적어도 2자리 이상의 칸을 확보해야 한다.
//     - x축 라벨의 특정 지점의 값이 10 ~ 99 사이라면 적어도 3자리 이상의 칸을 확보해야 한다.
//     - x축 라벨의 특정 지점의 값이 100 ~ 999 사이라면 적어도 4자리 이상의 칸을 확보해야 한다.
//     - ...
// 즉, 음수와 양수를 기준으로 가장 큰 number_length를 구하고, 음수의 경우에는 1을 더해준 뒤
// setw(number_length + 1)을 이용하여 일괄적으로 출력하면 된다.
// 출력시에는 물론 그래프 내부의 그리드도 이와 같은 간격을 유지해야 한다.
// 정렬을 위해, 그래프 내부의 그리드 값 (ex. ., -, |, +, x) 은 모두 1자리로 고정하고, 숫자의 첫번째 자리에 맞추어서 출력한다.
// 따라서 setw(number_length)에 오른쪽 정렬을 적용하면 된다.
