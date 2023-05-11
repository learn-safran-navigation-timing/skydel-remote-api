
#include "gen/SetElevationMaskAbove.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetElevationMaskAbove
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetElevationMaskAbove::CmdName = "SetElevationMaskAbove";
    const char* const SetElevationMaskAbove::Documentation = "Set elevation mask angle. See command EnableElevationMaskAbove";

    REGISTER_COMMAND_FACTORY(SetElevationMaskAbove);


    SetElevationMaskAbove::SetElevationMaskAbove()
      : CommandBase(CmdName)
    {}

    SetElevationMaskAbove::SetElevationMaskAbove(double angle)
      : CommandBase(CmdName)
    {

      setAngle(angle);
    }

    SetElevationMaskAbovePtr SetElevationMaskAbove::create(double angle)
    {
      return std::make_shared<SetElevationMaskAbove>(angle);
    }

    SetElevationMaskAbovePtr SetElevationMaskAbove::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetElevationMaskAbove>(ptr);
    }

    bool SetElevationMaskAbove::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Angle"])
        ;

    }

    std::string SetElevationMaskAbove::documentation() const { return Documentation; }


    int SetElevationMaskAbove::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetElevationMaskAbove::angle() const
    {
      return parse_json<double>::parse(m_values["Angle"]);
    }

    void SetElevationMaskAbove::setAngle(double angle)
    {
      m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
