
#include "gen/IsLogDownlinkEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogDownlinkEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogDownlinkEnabledResult::CmdName = "IsLogDownlinkEnabledResult";
    const char* const IsLogDownlinkEnabledResult::Documentation = "Result of IsLogDownlinkEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsLogDownlinkEnabledResult);


    IsLogDownlinkEnabledResult::IsLogDownlinkEnabledResult()
      : CommandResult(CmdName)
    {}

    IsLogDownlinkEnabledResult::IsLogDownlinkEnabledResult(bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
      setBeforeEncoding(beforeEncoding);
      setAfterEncoding(afterEncoding);
    }

    IsLogDownlinkEnabledResult::IsLogDownlinkEnabledResult(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
      setBeforeEncoding(beforeEncoding);
      setAfterEncoding(afterEncoding);
    }


    IsLogDownlinkEnabledResultPtr IsLogDownlinkEnabledResult::create(bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
    {
      return std::make_shared<IsLogDownlinkEnabledResult>(enabled, beforeEncoding, afterEncoding);
    }

    IsLogDownlinkEnabledResultPtr IsLogDownlinkEnabledResult::create(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
    {
      return std::make_shared<IsLogDownlinkEnabledResult>(relatedCommand, enabled, beforeEncoding, afterEncoding);
    }

    IsLogDownlinkEnabledResultPtr IsLogDownlinkEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLogDownlinkEnabledResult>(ptr);
    }

    bool IsLogDownlinkEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["BeforeEncoding"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["AfterEncoding"])
        ;

    }

    std::string IsLogDownlinkEnabledResult::documentation() const { return Documentation; }


    bool IsLogDownlinkEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLogDownlinkEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> IsLogDownlinkEnabledResult::beforeEncoding() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["BeforeEncoding"]);
    }

    void IsLogDownlinkEnabledResult::setBeforeEncoding(const Sdx::optional<bool>& beforeEncoding)
    {
      m_values.AddMember("BeforeEncoding", parse_json<Sdx::optional<bool>>::format(beforeEncoding, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> IsLogDownlinkEnabledResult::afterEncoding() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["AfterEncoding"]);
    }

    void IsLogDownlinkEnabledResult::setAfterEncoding(const Sdx::optional<bool>& afterEncoding)
    {
      m_values.AddMember("AfterEncoding", parse_json<Sdx::optional<bool>>::format(afterEncoding, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
