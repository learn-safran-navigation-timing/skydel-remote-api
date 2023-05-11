
#include "gen/GetSpoofTxColorResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxColorResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxColorResult::CmdName = "GetSpoofTxColorResult";
    const char* const GetSpoofTxColorResult::Documentation = "Result of GetSpoofTxColor.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSpoofTxColorResult);


    GetSpoofTxColorResult::GetSpoofTxColorResult()
      : CommandResult(CmdName)
    {}

    GetSpoofTxColorResult::GetSpoofTxColorResult(const std::string& color, const std::string& id)
      : CommandResult(CmdName)
    {

      setColor(color);
      setId(id);
    }

    GetSpoofTxColorResult::GetSpoofTxColorResult(CommandBasePtr relatedCommand, const std::string& color, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setColor(color);
      setId(id);
    }


    GetSpoofTxColorResultPtr GetSpoofTxColorResult::create(const std::string& color, const std::string& id)
    {
      return std::make_shared<GetSpoofTxColorResult>(color, id);
    }

    GetSpoofTxColorResultPtr GetSpoofTxColorResult::create(CommandBasePtr relatedCommand, const std::string& color, const std::string& id)
    {
      return std::make_shared<GetSpoofTxColorResult>(relatedCommand, color, id);
    }

    GetSpoofTxColorResultPtr GetSpoofTxColorResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxColorResult>(ptr);
    }

    bool GetSpoofTxColorResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Color"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxColorResult::documentation() const { return Documentation; }


    std::string GetSpoofTxColorResult::color() const
    {
      return parse_json<std::string>::parse(m_values["Color"]);
    }

    void GetSpoofTxColorResult::setColor(const std::string& color)
    {
      m_values.AddMember("Color", parse_json<std::string>::format(color, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxColorResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxColorResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
