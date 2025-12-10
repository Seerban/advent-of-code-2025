package main

import (
	"fmt"
	"os"
	"strings"
)

var neighbours = [][]int{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}
var lines [][]byte

func read_lines() {
	file, _ := os.ReadFile("input.txt")
	strlines := strings.Split(string(file), "\n")
	lines = make([][]byte, len(strlines))
	// turn to byte matrix
	for i := range strlines {
		lines[i] = []byte(strlines[i])
	}
	// remove endline byte
	for i := range lines {
		if len(lines[i]) > 0 {
			lines[i] = lines[i][:len(lines[i])-1]
		}
	}
}

func count_neighbours(x int, y int) int {
	total := 0
	for i := 0; i < len(neighbours); i++ {
		xi := x + neighbours[i][0]
		yi := y + neighbours[i][1]
		if xi < 0 || yi < 0 {
			continue
		}
		if yi >= len(lines) || xi >= len(lines[0]) {
			continue
		}
		if lines[yi][xi] == '@' {
			total += 1
		}
	}
	return total
}

func remove_removable() int {
	total := 0
	for i := 0; i < len(lines); i++ {
		for j := 0; j < len(lines[0]); j++ {
			if lines[i][j] == '.' {
				continue
			}
			if count_neighbours(j, i) < 4 {
				lines[i][j] = '.'
				total += 1
			}
		}
	}
	return total
}

func main() {
	read_lines()

	sum := remove_removable()

	fmt.Println(sum)
}
