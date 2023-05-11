
#include "gen/SetPowerForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPowerForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPowerForSV::CmdName = "SetPowerForSV";
    const char* const SetPowerForSV::Documentation = "Please note the command SetPowerForSV is deprecated since 22.7. You may use SetManualPowerOffsetForSV.\n\nSet power offset for specified satellite SV ID. Use SV ID 0 to set power for all satellites.";

    const char* const SetPowerForSV::Deprecated = "Please note the command SetPowerForSV is deprecated since 22.7. You may use SetManualPowerOffsetForSV.";

    REGISTER_COMMAND_FACTORY(SetPowerForSV);


    SetPowerForSV::SetPowerForSV()
      : CommandBase(CmdName)
    {}

    SetPowerForSV::SetPowerForSV(const std::string& system, int svId, double powerOffset, bool otherSatsFollow)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setPowerOffset(powerOffset);
      setOtherSatsFollow(otherSatsFollow);
    }

    SetPowerForSVPtr SetPowerForSV::create(const std::string& system, int svId, double powerOffset, bool otherSatsFollow)
    {
      return std::make_shared<SetPowerForSV>(system, svId, powerOffset, otherSatsFollow);
    }

    SetPowerForSVPtr SetPowerForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPowerForSV>(ptr);
    }

    bool SetPowerForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["PowerOffset"])
          && parse_json<bool>::is_valid(m_values["OtherSatsFollow"])
        ;

    }

    std::string SetPowerForSV::documentation() const { return Documentation; }

    Sdx::optional<std::string> SetPowerForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetPowerForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string SetPowerForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPowerForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPowerForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPowerForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPowerForSV::powerOffset() const
    {
      return parse_json<double>::parse(m_values["PowerOffset"]);
    }

    void SetPowerForSV::setPowerOffset(double powerOffset)
    {
      m_values.AddMember("PowerOffset", parse_json<double>::format(powerOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPowerForSV::otherSatsFollow() const
    {
      return parse_json<bool>::parse(m_values["OtherSatsFollow"]);
    }

    void SetPowerForSV::setOtherSatsFollow(bool otherSatsFollow)
    {
      m_values.AddMember("OtherSatsFollow", parse_json<bool>::format(otherSatsFollow, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
