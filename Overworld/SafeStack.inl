//
//  SafeStack.cpp
//  Overworld
//
//  Created by Noah Kittleson on 8/7/19.
//  Copyright © 2019 Noah. All rights reserved.
//

template <typename T>
SafeStack<T>::~SafeStack()
{
	
}

template <typename T>
void SafeStack<T>::popTop()
{
	objectStack.pop();
}

template <typename T>
void SafeStack<T>::addT(std::unique_ptr<T>&& addMe)
{
	if (addMe) {
		objectStack.push(std::move(addMe));
	}
}

template <typename T>
void SafeStack<T>::clear()
{
	while (!objectStack.empty()) {
		objectStack.pop();
	}
}

template <typename T>
SafeStack<T>::PendingChange::PendingChange(States::Action action, std::unique_ptr<T>&& add)
: action (action), add(std::move(add))
{
	
}

template <typename T>
std::unique_ptr<T>& SafeStack<T>::getCurrentT()
{
	assert(!objectStack.empty());
	return objectStack.front();
}

template <typename T>
bool SafeStack<T>::empty() const
{
	return objectStack.empty();
}

template <typename T>
void SafeStack<T>::requestAdd(std::unique_ptr<T>&& add)
{
	pendingChanges.emplace_back(PendingChange(States::Add, std::move(add)));
}

template <typename T>
void SafeStack<T>::requestClear()
{
	pendingChanges.emplace_back(PendingChange(States::Clear));
}

template <typename T>
void SafeStack<T>::requestPop()
{
	pendingChanges.emplace_back(PendingChange(States::Pop));
}

template <typename T>
void SafeStack<T>::applyPendingChanges()
{
	for (auto & change : pendingChanges) {
		switch (change.action) {
			case States::Add:
				addState(std::move(change.add));
				break;
				
			case States::Pop:
				popTop();
				break;
				
			case States::Clear:
				clear();
				break;
				
			default:
				break;
		}
	}
	pendingChanges.clear();
}

