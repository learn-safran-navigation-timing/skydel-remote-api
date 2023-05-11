
#include "gen/SetElevationMaskBelow.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetElevationMaskBelow
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetElevationMaskBelow::CmdName = "SetElevationMaskBelow";
    const char* const SetElevationMaskBelow::Documentation = "Set elevation mask angle. See command EnableElevationMaskBelow";

    REGISTER_COMMAND_FACTORY(SetElevationMaskBelow);


    SetElevationMaskBelow::SetElevationMaskBelow()
      : CommandBase(CmdName)
    {}

    SetElevationMaskBelow::SetElevationMaskBelow(double angle)
      : CommandBase(CmdName)
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
