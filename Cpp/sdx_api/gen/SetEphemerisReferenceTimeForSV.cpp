
#include "SetEphemerisReferenceTimeForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEphemerisReferenceTimeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEphemerisReferenceTimeForSV::CmdName = "SetEphemerisReferenceTimeForSV";
    const char* const SetEphemerisReferenceTimeForSV::Documentation = "Set the ephemeris reference time for the specified constellation.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId        int             The satellite's SV ID.\n"
      "Time        datetime        GPS date and time (it is the GPS time expressed in UTC format)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetEphemerisReferenceTimeForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetEphemerisReferenceTimeForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetEphemerisReferenceTimeForSV);


    SetEphemerisReferenceTimeForSV::SetEphemerisReferenceTimeForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetEphemerisReferenceTimeForSV::SetEphemerisReferenceTimeForSV(const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setTime(time);
      setDataSetName(dataSetName);
    }

    SetEphemerisReferenceTimeForSVPtr SetEphemerisReferenceTimeForSV::create(const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetEphemerisReferenceTimeForSV>(system, svId, time, dataSetName);
    }

    SetEphemerisReferenceTimeForSVPtr SetEphemerisReferenceTimeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEphemerisReferenceTimeForSV>(ptr);
    }

    bool SetEphemerisReferenceTimeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetEphemerisReferenceTimeForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetEphemerisReferenceTimeForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Time", "DataSetName"}; 
      return names; 
    }


    int SetEphemerisReferenceTimeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetEphemerisReferenceTimeForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetEphemerisReferenceTimeForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetEphemerisReferenceTimeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetEphemerisReferenceTimeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetEphemerisReferenceTimeForSV::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void SetEphemerisReferenceTimeForSV::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetEphemerisReferenceTimeForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetEphemerisReferenceTimeForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
