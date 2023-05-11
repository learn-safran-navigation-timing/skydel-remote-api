
#include "gen/GetEphemerisReferenceTime.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisReferenceTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisReferenceTime::CmdName = "GetEphemerisReferenceTime";
    const char* const GetEphemerisReferenceTime::Documentation = "Please note the command GetEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.\n\nGet the ephemeris reference time for the specified constellation.";

    REGISTER_COMMAND_FACTORY(GetEphemerisReferenceTime);


    GetEphemerisReferenceTime::GetEphemerisReferenceTime()
      : CommandBase(CmdName)
    {}

    GetEphemerisReferenceTime::GetEphemerisReferenceTime(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetEphemerisReferenceTimePtr GetEphemerisReferenceTime::create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetEphemerisReferenceTime>(system, svId, dataSetName);
    }

    GetEphemerisReferenceTimePtr GetEphemerisReferenceTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisReferenceTime>(ptr);
    }

    bool GetEphemerisReferenceTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetEphemerisReferenceTime::documentation() const { return Documentation; }


    int GetEphemerisReferenceTime::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisReferenceTime::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisReferenceTime::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisReferenceTime::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisReferenceTime::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetEphemerisReferenceTime::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetEphemerisReferenceTime::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
