//
//  make_unique.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/13/19.
//  Copyright © 2019 Noah. All rights reserved.
//

#pragma once

template <typename Creation, typename... ParamTypes>
std::unique_ptr<Creation> make_unique(ParamTypes&& ... params)
{
	return std::unique_ptr<Creation>(new Creation(std::forward<ParamTypes>(params)...));
}
