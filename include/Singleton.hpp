#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class Singleton
{
public:
	static T* GetInstance()
	{
		if (!m_instance)
		{
			m_instance = new T();
		}
		return m_instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator= (const Singleton) = delete;

protected:
	Singleton() {}
	~Singleton() {}

private:
	inline static T* m_instance = nullptr;
};

#endif
