#pragma once

template <typename T>
class Singleton abstract
{
private:
	static T* instance;
public:
	virtual ~Singleton() {}

	virtual void Release()
	{
		SAFE_DELETE(instance);
	}

	static T* GetInstance()
	{
		if (instance == nullptr)
			instance = new T;

		return instance;
	}
};

template <typename T>
T* Singleton<T>::instance = nullptr;
