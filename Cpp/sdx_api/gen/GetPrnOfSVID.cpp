
#include "GetPrnOfSVID.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnOfSVID
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnOfSVID::CmdName = "GetPrnOfSVID";
    const char* const GetPrnOfSVID::Documentation = "Get the PRN transmitted by the SV ID for this signal.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\"\n"
      "SvId   int    Satellite SV ID.";
    const char* const GetPrnOfSVID::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPrnOfSVID);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPrnOfSVID);


    GetPrnOfSVID::GetPrnOfSVID()
      : CommandBase(CmdName, TargetId)
    {}

    GetPrnOfSVID::GetPrnOfSVID(const std::string& signal, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setSvId(svId);
    }

    GetPrnOfSVIDPtr GetPrnOfSVID::create(const std::string& signal, int svId)
    {
      return std::make_shared<GetPrnOfSVID>(signal, svId);
    }

    GetPrnOfSVIDPtr GetPrnOfSVID::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnOfSVID>(ptr);
    }

    bool GetPrnOfSVID::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetPrnOfSVID::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPrnOfSVID::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId"}; 
      return names; 
    }


    int GetPrnOfSVID::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPrnOfSVID::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPrnOfSVID::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPrnOfSVID::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPrnOfSVID::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
