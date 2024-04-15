
#include "GetElevationMaskAboveResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationMaskAboveResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationMaskAboveResult::CmdName = "GetElevationMaskAboveResult";
    const char* const GetElevationMaskAboveResult::Documentation = "Result of GetElevationMaskAbove.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ---------------------------\n"
      "Angle double Elevation mask angle in rad";
    const char* const GetElevationMaskAboveResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationMaskAboveResult);


    GetElevationMaskAboveResult::GetElevationMaskAboveResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetElevationMaskAboveResult::GetElevationMaskAboveResult(double angle)
      : CommandResult(CmdName, TargetId)
    {

      setAngle(angle);
    }

    GetElevationMaskAboveResult::GetElevationMaskAboveResult(CommandBasePtr relatedCommand, double angle)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setAngle(angle);
    }


    GetElevationMaskAboveResultPtr GetElevationMaskAboveResult::create(double angle)
    {
      return std::make_shared<GetElevationMaskAboveResult>(angle);
    }

    GetElevationMaskAboveResultPtr GetElevationMaskAboveResult::create(CommandBasePtr relatedCommand, double angle)
    {
      return std::make_shared<GetElevationMaskAboveResult>(relatedCommand, angle);
    }

    GetElevationMaskAboveResultPtr GetElevationMaskAboveResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationMaskAboveResult>(ptr);
    }

    bool GetElevationMaskAboveResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Angle"])
        ;

    }

    std::string GetElevationMaskAboveResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetElevationMaskAboveResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Angle"}; 
      return names; 
    }


    double GetElevationMaskAboveResult::angle() const
    {
      return parse_json<double>::parse(m_values["Angle"]);
    }

    void GetElevationMaskAboveResult::setAngle(double angle)
    {
      m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
