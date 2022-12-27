#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

int main()
{  
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	std::vector<std::vector<int>> grid;
	int n, m;
	fin >> n >> m;
	grid.resize(n);
	for (int i = 0; i < n; ++i)
	{
		grid[i].resize(m);
		for (int j = 0; j < m; ++j) {
			fin >> grid[i][j];
		}
	}

	std::vector<std::vector<bool>> visited;
	std::vector<std::vector<int>> dist;

	visited.resize(n);
	dist.resize(n);

	for (int i = 0; i < n; ++i)
	{
		dist[i].resize(m, -1);
		visited[i].resize(m, false);
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 1) {
				visited[i][j] = true;
			}
		}
	}

	std::pair<int, int> source;
	std::pair<int, int> dest;

	fin >> source.first >> source.second;
	fin >> dest.first >> dest.second;

	dist[source.first][source.second] = 0;
	visited[source.first][source.second] = true;

	std::queue<std::pair<int, int>> q;
	q.push(source);
	while (!q.empty()) {
		const std::pair<int, int> p = q.front();
		q.pop();
		if (p == dest) {
			break;
		}

		const int i = p.first;
		const int j = p.second;

		if (i - 1 >= 0 && !visited[i - 1][j]) {
			visited[i - 1][j] = true;
			dist[i - 1][j] = dist[i][j] + 1;
			q.push(std::make_pair(i - 1, j));
		}
		if (i + 1 < n && !visited[i + 1][j]) {
			visited[i + 1][j] = true;
			dist[i + 1][j] = dist[i][j] + 1;
			q.push(std::make_pair(i + 1, j));
		}
		if (j - 1 >= 0 && !visited[i][j - 1]) {
			visited[i][j - 1] = true;
			dist[i][j - 1] = dist[i][j] + 1;
			q.push(std::make_pair(i, j - 1));
		}
		if (j + 1 < m && !visited[i][j + 1]) {
			visited[i][j + 1] = true;
			dist[i][j + 1] = dist[i][j] + 1;
			q.push(std::make_pair(i, j + 1));
		}
	}

	fout << dist[dest.first][dest.second] << std::endl;
	system("pause");

	return 0;
}
