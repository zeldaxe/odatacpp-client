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

#include "odata/common/utility.h"
#include "odata/core/odata_core.h"
#include "cpprest/json.h"
#include "odata/edm/odata_edm.h"

namespace odata { namespace core
{

class odata_contex_url_parser
{
public:
	odata_contex_url_parser(std::shared_ptr<::odata::edm::edm_model> model, ::utility::string_t service_root_url) 
		: m_model(model), m_service_root_url(std::move(service_root_url))
	{
	}

	ODATACPP_CLIENT_API std::shared_ptr<::odata::edm::edm_named_type> get_payload_content_type(const ::utility::string_t& context_url);

private:
	std::shared_ptr<::odata::edm::edm_named_type> parse_context_url(std::list<::utility::string_t>& paths, const std::shared_ptr<::odata::edm::edm_named_type>& current_type);
	std::shared_ptr<::odata::edm::edm_named_type> parse_complex_or_primitive(const ::utility::string_t& current_path);

	std::shared_ptr<::odata::edm::edm_model>  m_model;
	::utility::string_t m_service_root_url; 
};

}}