
#include "gen/GetManualPowerOffsetForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetManualPowerOffsetForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetManualPowerOffsetForSV::CmdName = "GetManualPowerOffsetForSV";
    const char* const GetManualPowerOffsetForSV::Documentation = "Get the power offsets for specific signals of a satellite.";

    REGISTER_COMMAND_FACTORY(GetManualPowerOffsetForSV);


    GetManualPowerOffsetForSV::GetManualPowerOffsetForSV()
      : CommandBase(CmdName)
    {}

    GetManualPowerOffsetForSV::GetManualPowerOffsetForSV(const std::string& system, int svId, const std::vector<std::string>& signalArray)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setSignalArray(signalArray);
    }

    GetManualPowerOffsetForSVPtr GetManualPowerOffsetForSV::create(const std::string& system, int svId, const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetManualPowerOffsetForSV>(system, svId, signalArray);
    }

    GetManualPowerOffsetForSVPtr GetManualPowerOffsetForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetManualPowerOffsetForSV>(ptr);
    }

    bool GetManualPowerOffsetForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetManualPowerOffsetForSV::documentation() const { return Documentation; }


    int GetManualPowerOffsetForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetManualPowerOffsetForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetManualPowerOffsetForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetManualPowerOffsetForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetManualPowerOffsetForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetManualPowerOffsetForSV::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetManualPowerOffsetForSV::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
