
#include "GetSVDataUpdateModeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVDataUpdateModeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVDataUpdateModeResult::CmdName = "GetSVDataUpdateModeResult";
    const char* const GetSVDataUpdateModeResult::Documentation = "Result of GetSVDataUpdateMode.\n"
      "\n"
      "Name Type             Description\n"
      "---- ---------------- ------------------------------------------------------------------\n"
      "Mode SVDataUpdateMode SV Data Update Mode:\n"
      "                      Extrapolation: Skydel extrapolates from the first block (default).\n"
      "                      Dynamic: Blocks must be pushed during the simulation.";
    const char* const GetSVDataUpdateModeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVDataUpdateModeResult);


    GetSVDataUpdateModeResult::GetSVDataUpdateModeResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSVDataUpdateModeResult::GetSVDataUpdateModeResult(const Sdx::SVDataUpdateMode& mode)
      : CommandResult(CmdName, TargetId)
    {

      setMode(mode);
    }

    GetSVDataUpdateModeResult::GetSVDataUpdateModeResult(CommandBasePtr relatedCommand, const Sdx::SVDataUpdateMode& mode)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMode(mode);
    }


    GetSVDataUpdateModeResultPtr GetSVDataUpdateModeResult::create(const Sdx::SVDataUpdateMode& mode)
    {
      return std::make_shared<GetSVDataUpdateModeResult>(mode);
    }

    GetSVDataUpdateModeResultPtr GetSVDataUpdateModeResult::create(CommandBasePtr relatedCommand, const Sdx::SVDataUpdateMode& mode)
    {
      return std::make_shared<GetSVDataUpdateModeResult>(relatedCommand, mode);
    }

    GetSVDataUpdateModeResultPtr GetSVDataUpdateModeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVDataUpdateModeResult>(ptr);
    }

    bool GetSVDataUpdateModeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::SVDataUpdateMode>::is_valid(m_values["Mode"])
        ;

    }

    std::string GetSVDataUpdateModeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVDataUpdateModeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Mode"}; 
      return names; 
    }


    Sdx::SVDataUpdateMode GetSVDataUpdateModeResult::mode() const
    {
      return parse_json<Sdx::SVDataUpdateMode>::parse(m_values["Mode"]);
    }

    void GetSVDataUpdateModeResult::setMode(const Sdx::SVDataUpdateMode& mode)
    {
      m_values.AddMember("Mode", parse_json<Sdx::SVDataUpdateMode>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
