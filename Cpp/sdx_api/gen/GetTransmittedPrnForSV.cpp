
#include "gen/GetTransmittedPrnForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTransmittedPrnForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTransmittedPrnForSV::CmdName = "GetTransmittedPrnForSV";
    const char* const GetTransmittedPrnForSV::Documentation = "Get the PRNs transmitted by the SV ID for these signals.";

    REGISTER_COMMAND_FACTORY(GetTransmittedPrnForSV);


    GetTransmittedPrnForSV::GetTransmittedPrnForSV()
      : CommandBase(CmdName)
    {}

    GetTransmittedPrnForSV::GetTransmittedPrnForSV(int svId, const std::vector<std::string>& signalArray)
      : CommandBase(CmdName)
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
