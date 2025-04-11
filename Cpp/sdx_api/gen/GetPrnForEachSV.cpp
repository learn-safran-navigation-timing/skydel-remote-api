
#include "GetPrnForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnForEachSV::CmdName = "GetPrnForEachSV";
    const char* const GetPrnForEachSV::Documentation = "Get the PRN for each satellite for specified signals.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"";
    const char* const GetPrnForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPrnForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPrnForEachSV);


    GetPrnForEachSV::GetPrnForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPrnForEachSV::GetPrnForEachSV(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    GetPrnForEachSVPtr GetPrnForEachSV::create(const std::string& signal)
    {
      return std::make_shared<GetPrnForEachSV>(signal);
    }

    GetPrnForEachSVPtr GetPrnForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnForEachSV>(ptr);
    }

    bool GetPrnForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetPrnForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPrnForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int GetPrnForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPrnForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPrnForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
