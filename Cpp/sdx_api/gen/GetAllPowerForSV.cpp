
#include "gen/GetAllPowerForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllPowerForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllPowerForSV::CmdName = "GetAllPowerForSV";
    const char* const GetAllPowerForSV::Documentation = "Get the power information for the specified satellite.";

    REGISTER_COMMAND_FACTORY(GetAllPowerForSV);


    GetAllPowerForSV::GetAllPowerForSV()
      : CommandBase(CmdName)
    {}

    GetAllPowerForSV::GetAllPowerForSV(const std::string& system, int svId, const std::vector<std::string>& signalArray)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setSignalArray(signalArray);
    }

    GetAllPowerForSVPtr GetAllPowerForSV::create(const std::string& system, int svId, const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetAllPowerForSV>(system, svId, signalArray);
    }

    GetAllPowerForSVPtr GetAllPowerForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllPowerForSV>(ptr);
    }

    bool GetAllPowerForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetAllPowerForSV::documentation() const { return Documentation; }


    int GetAllPowerForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetAllPowerForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllPowerForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllPowerForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllPowerForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetAllPowerForSV::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetAllPowerForSV::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
