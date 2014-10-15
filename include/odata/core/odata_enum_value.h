/*
 * Copyright (c) Microsoft Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#pragma once

#include "odata/edm/odata_edm.h"
#include "odata/core/odata_value.h"

namespace odata { namespace core
{

class odata_enum_value : public odata_value
{
public:
    odata_enum_value(std::shared_ptr<::odata::edm::edm_named_type>type, ::utility::string_t stringRep) : odata_value(type), m_string_rep(std::move(stringRep))
    {
    }

    const ::utility::string_t& to_string() const
    {
        return m_string_rep; 
    }

private:
	::utility::string_t    m_string_rep;

};

}}