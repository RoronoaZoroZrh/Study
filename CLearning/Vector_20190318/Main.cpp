#include <vector>

int main(int argc, const char* argv[])
{
	//vector�������ʼ��
	std::vector<int> vec1;
	printf("vec1.size=%zd\n", vec1.size());
	std::vector<int> vec2(vec1);
	printf("vec2.size=%zd\n", vec2.size());

	system("Pause");
	return 0;
}