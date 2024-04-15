
#include "GetIntTxColorResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxColorResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxColorResult::CmdName = "GetIntTxColorResult";
    const char* const GetIntTxColorResult::Documentation = "Result of GetIntTxColor.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -------------------------------------------------------------------------------\n"
      "Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).\n"
      "Id    string Transmitter unique identifier.";
    const char* const GetIntTxColorResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxColorResult);


    GetIntTxColorResult::GetIntTxColorResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxColorResult::GetIntTxColorResult(const std::string& color, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setColor(color);
      setId(id);
    }

    GetIntTxColorResult::GetIntTxColorResult(CommandBasePtr relatedCommand, const std::string& color, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setColor(color);
      setId(id);
    }


    GetIntTxColorResultPtr GetIntTxColorResult::create(const std::string& color, const std::string& id)
    {
      return std::make_shared<GetIntTxColorResult>(color, id);
    }

    GetIntTxColorResultPtr GetIntTxColorResult::create(CommandBasePtr relatedCommand, const std::string& color, const std::string& id)
    {
      return std::make_shared<GetIntTxColorResult>(relatedCommand, color, id);
    }

    GetIntTxColorResultPtr GetIntTxColorResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxColorResult>(ptr);
    }

    bool GetIntTxColorResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Color"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxColorResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxColorResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Color", "Id"}; 
      return names; 
    }


    std::string GetIntTxColorResult::color() const
    {
      return parse_json<std::string>::parse(m_values["Color"]);
    }

    void GetIntTxColorResult::setColor(const std::string& color)
    {
      m_values.AddMember("Color", parse_json<std::string>::format(color, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxColorResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxColorResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
