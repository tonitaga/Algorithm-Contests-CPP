class Point:
    def __init__(self, row, col):
        self.row = row
        self.col = col


class WaveAlgorithm:
    def get_path_length(self, matrix, start: Point, finish: Point, empty) -> int:
        self.__initialize_start_state(matrix, start, finish)

        while len(self.__old_wave) != 0:
            if self.__step_wave(matrix, finish, empty):
                break

        return self.__make_path(matrix, finish, empty)

    def __initialize_start_state(self, matrix, start: Point, finish) -> None:
        self.__wave = []
        self.__old_wave = [start]
        self.__wave_step = 0
        self.__length_map = []

        for _ in range(len(matrix)):
            self.__length_map.append([-1] * len(matrix[0]))

        self.__length_map[start.row][start.col] = 0

    def __get_neighbors(self, matrix, pos: Point) -> list:
        neighbors = []

        row, col = pos.row, pos.col

        if row - 1 >= 0:
            neighbors.append(Point(row - 1, col))
        if row + 1 < len(matrix):
            neighbors.append(Point(row + 1, col))
        if col - 1 >= 0:
            neighbors.append(Point(row, col - 1))
        if col + 1 < len(matrix[0]):
            neighbors.append(Point(row, col + 1))

        return neighbors

    def __make_path(self, matrix, finish: Point, empty) -> int:
        if self.__length_map[finish.row][finish.col] == -1:
            return 0

        row, col = finish.row, finish.col
        length = 0

        while self.__length_map[row][col] != 0:
            compare_var = self.__length_map[row][col]
            neighbors = self.__get_neighbors(matrix, Point(row, col))
            for pos in neighbors:
                x, y = pos.row, pos.col
                if self.__length_map[x][y] + 1 == compare_var and matrix[x][y] == empty:
                    row = x
                    col = y
                    length += 1
                    break

        return length

    def __step_wave(self, matrix, finish: Point, empty) -> bool:
        self.__wave_step += 1

        for pos in self.__old_wave:
            neighbors = self.__get_neighbors(matrix, pos)
            for check_pos in neighbors:
                x, y = check_pos.row, check_pos.col
                if matrix[x][y] == empty:
                    if self.__length_map[x][y] == -1:
                        self.__wave.append(Point(x, y))
                        self.__length_map[x][y] = self.__wave_step

                    if x == finish.row and y == finish.col:
                        return True

        self.__old_wave = list(self.__wave)
        self.__wave.clear()

        return False


def main():
    rows, cols = [int(x) for x in input().split()]
    scol, srow = [int(x) for x in input().split()]
    fcol, frow = [int(x) for x in input().split()]

    matrix = []
    for _ in range(rows):
        matrix.append([int(x) for x in input().split()])

    wave_algorithm = WaveAlgorithm()
    print(wave_algorithm.get_path_length(matrix, Point(srow, scol), Point(frow, fcol), 0))


if __name__ == '__main__':
    main()
