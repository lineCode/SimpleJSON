#pragma once

#include "jsd_core.hpp"
#include "../utility/tmp_util/type_of_size.hpp"

namespace JSON
{
	template <typename T,
			  class = typename std::enable_if<  (std::is_arithmetic<T>::value && !std::is_same<T, char>::value && !std::is_same<T, wchar_t>::value)
                                              && !std::is_enum<T>::value         >::type
			 >
	void parse(T& value, std::string const& name,
			   PropertyTree const& object, ParsingOptions const& options = DEFAULT_PARSER_OPTIONS)
	{
		try
		{
		    GET_VALUE(T, name, value, T());
		}
		catch (boost::property_tree::ptree_bad_data& exc)
		{
			DEFAULT_PROPERTY_ERROR_HANDLER(T(), T());
		}
        catch (boost::property_tree::ptree_bad_path& exc)
        {
			DEFAULT_PATH_ERROR_HANDLER(T(), T());
        }
	}

	void parse(char& value, std::string const& name,
               PropertyTree const& object, ParsingOptions const& options = DEFAULT_PARSER_OPTIONS);
    void parse(wchar_t& value, std::string const& name,
			   PropertyTree const& object, ParsingOptions const& options = DEFAULT_PARSER_OPTIONS);
}
