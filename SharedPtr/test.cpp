#include <memory>
#include <iostream>

class session
{
public:
	~session()
	{
		std::cout << "~session\n";
	}

	void print()
	{
	}
};

void main()
{
	std::shared_ptr<session> ses = std::make_shared<session>();
	std::cout << "ses count = " << ses.use_count() << "\n";

	auto two = ses;
	std::cout << "ses count = " << ses.use_count() << "\n";
	std::cout << "two count = " << two.use_count() << "\n";

	auto& three = ses;
	std::cout << "three count = " << three.use_count() << "\n";

	ses.reset();
	std::cout << "ses count = " << ses.use_count() << "\n";
}