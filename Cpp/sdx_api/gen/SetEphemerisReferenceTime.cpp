
#include "gen/SetEphemerisReferenceTime.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEphemerisReferenceTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEphemerisReferenceTime::CmdName = "SetEphemerisReferenceTime";
    const char* const SetEphemerisReferenceTime::Documentation = "Please note the command SetEphemerisReferenceTime is deprecated since 21.3. You may use SetEphemerisReferenceTimeForSV.\n\nSet the ephemeris reference time for the specified constellation.";

    REGISTER_COMMAND_FACTORY(SetEphemerisReferenceTime);


    SetEphemerisReferenceTime::SetEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    SetEphemerisReferenceTime::SetEphemerisReferenceTime(const std::string& system, int svId, const Sdx::DateTime& time, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setTime(time);
      setDataSetName(dataSetName);
    }

    SetEphemerisReferenceTimePtr SetEphemerisReferenceTime::create(const std::string& system, int svId, const Sdx::DateTime& time, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetEphemerisReferenceTime>(system, svId, time, dataSetName);
    }

    SetEphemerisReferenceTimePtr SetEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEphemerisReferenceTime>(ptr);
    }

    bool SetEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetEphemerisReferenceTime::documentation() const { return Documentation; }


    int SetEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetEphemerisReferenceTime::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetEphemerisReferenceTime::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetEphemerisReferenceTime::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetEphemerisReferenceTime::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetEphemerisReferenceTime::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void SetEphemerisReferenceTime::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetEphemerisReferenceTime::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetEphemerisReferenceTime::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
