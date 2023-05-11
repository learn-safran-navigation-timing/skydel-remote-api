
#include "gen/GetElevationMaskAboveResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationMaskAboveResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationMaskAboveResult::CmdName = "GetElevationMaskAboveResult";
    const char* const GetElevationMaskAboveResult::Documentation = "Result of GetElevationMaskAbove.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetElevationMaskAboveResult);


    GetElevationMaskAboveResult::GetElevationMaskAboveResult()
      : CommandResult(CmdName)
    {}

    GetElevationMaskAboveResult::GetElevationMaskAboveResult(double angle)
      : CommandResult(CmdName)
    {

      setAngle(angle);
    }

    GetElevationMaskAboveResult::GetElevationMaskAboveResult(CommandBasePtr relatedCommand, double angle)
      : CommandResult(CmdName, relatedCommand)
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
