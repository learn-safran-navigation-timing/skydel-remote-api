
#include "GetTransmittedPrnForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTransmittedPrnForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTransmittedPrnForSV::CmdName = "GetTransmittedPrnForSV";
    const char* const GetTransmittedPrnForSV::Documentation = "Get the PRNs transmitted by the SV ID for these signals.\n"
      "\n"
      "Name        Type         Description\n"
      "----------- ------------ ---------------------------------------------------------------------------\n"
      "SvId        int          Satellite SV ID.\n"
      "SignalArray array string An array of signals.\n"
      "                         Accepted values are: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\",\n"
      "                                              \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\",\n"
      "                                              \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\",\n"
      "                                              \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
      "                                              \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"";
    const char* const GetTransmittedPrnForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetTransmittedPrnForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTransmittedPrnForSV);


    GetTransmittedPrnForSV::GetTransmittedPrnForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetTransmittedPrnForSV::GetTransmittedPrnForSV(int svId, const std::vector<std::string>& signalArray)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setSignalArray(signalArray);
    }

    GetTransmittedPrnForSVPtr GetTransmittedPrnForSV::create(int svId, const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetTransmittedPrnForSV>(svId, signalArray);
    }

    GetTransmittedPrnForSVPtr GetTransmittedPrnForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTransmittedPrnForSV>(ptr);
    }

    bool GetTransmittedPrnForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetTransmittedPrnForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetTransmittedPrnForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "SignalArray"}; 
      return names; 
    }


    int GetTransmittedPrnForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetTransmittedPrnForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetTransmittedPrnForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetTransmittedPrnForSV::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetTransmittedPrnForSV::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
