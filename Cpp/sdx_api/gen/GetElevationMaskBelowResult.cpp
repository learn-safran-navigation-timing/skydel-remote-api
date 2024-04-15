
#include "GetElevationMaskBelowResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationMaskBelowResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationMaskBelowResult::CmdName = "GetElevationMaskBelowResult";
    const char* const GetElevationMaskBelowResult::Documentation = "Result of GetElevationMaskBelow.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ---------------------------\n"
      "Angle double Elevation mask angle in rad";
    const char* const GetElevationMaskBelowResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationMaskBelowResult);


    GetElevationMaskBelowResult::GetElevationMaskBelowResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetElevationMaskBelowResult::GetElevationMaskBelowResult(double angle)
      : CommandResult(CmdName, TargetId)
    {

      setAngle(angle);
    }

    GetElevationMaskBelowResult::GetElevationMaskBelowResult(CommandBasePtr relatedCommand, double angle)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setAngle(angle);
    }


    GetElevationMaskBelowResultPtr GetElevationMaskBelowResult::create(double angle)
    {
      return std::make_shared<GetElevationMaskBelowResult>(angle);
    }

    GetElevationMaskBelowResultPtr GetElevationMaskBelowResult::create(CommandBasePtr relatedCommand, double angle)
    {
      return std::make_shared<GetElevationMaskBelowResult>(relatedCommand, angle);
    }

    GetElevationMaskBelowResultPtr GetElevationMaskBelowResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationMaskBelowResult>(ptr);
    }

    bool GetElevationMaskBelowResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Angle"])
        ;

    }

    std::string GetElevationMaskBelowResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetElevationMaskBelowResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Angle"}; 
      return names; 
    }


    double GetElevationMaskBelowResult::angle() const
    {
      return parse_json<double>::parse(m_values["Angle"]);
    }

    void GetElevationMaskBelowResult::setAngle(double angle)
    {
      m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
