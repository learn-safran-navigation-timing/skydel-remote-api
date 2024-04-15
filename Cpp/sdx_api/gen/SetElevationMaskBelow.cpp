
#include "SetElevationMaskBelow.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetElevationMaskBelow
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetElevationMaskBelow::CmdName = "SetElevationMaskBelow";
    const char* const SetElevationMaskBelow::Documentation = "Set elevation mask angle. See command EnableElevationMaskBelow\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ---------------------------\n"
      "Angle double Elevation mask angle in rad";
    const char* const SetElevationMaskBelow::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetElevationMaskBelow);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetElevationMaskBelow);


    SetElevationMaskBelow::SetElevationMaskBelow()
      : CommandBase(CmdName, TargetId)
    {}

    SetElevationMaskBelow::SetElevationMaskBelow(double angle)
      : CommandBase(CmdName, TargetId)
    {

      setAngle(angle);
    }

    SetElevationMaskBelowPtr SetElevationMaskBelow::create(double angle)
    {
      return std::make_shared<SetElevationMaskBelow>(angle);
    }

    SetElevationMaskBelowPtr SetElevationMaskBelow::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetElevationMaskBelow>(ptr);
    }

    bool SetElevationMaskBelow::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Angle"])
        ;

    }

    std::string SetElevationMaskBelow::documentation() const { return Documentation; }

    const std::vector<std::string>& SetElevationMaskBelow::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Angle"}; 
      return names; 
    }


    int SetElevationMaskBelow::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetElevationMaskBelow::angle() const
    {
      return parse_json<double>::parse(m_values["Angle"]);
    }

    void SetElevationMaskBelow::setAngle(double angle)
    {
      m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
