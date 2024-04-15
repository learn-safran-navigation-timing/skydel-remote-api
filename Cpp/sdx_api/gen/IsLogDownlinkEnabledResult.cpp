
#include "IsLogDownlinkEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLogDownlinkEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLogDownlinkEnabledResult::CmdName = "IsLogDownlinkEnabledResult";
    const char* const IsLogDownlinkEnabledResult::Documentation = "Result of IsLogDownlinkEnabled.\n"
      "\n"
      "Name           Type          Description\n"
      "-------------- ------------- ----------------------------------------------------------------------------------------------------------------------\n"
      "Enabled        bool          If true, files will be created during simulation. By default, the downlink files will be created after signal encoding\n"
      "BeforeEncoding optional bool (Optional) If true, files will be created before signal encoding. Can be used with AfterEncoding\n"
      "AfterEncoding  optional bool (Optional) If true, files will be created after signal encoding. Can be used with BeforeEncoding";
    const char* const IsLogDownlinkEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsLogDownlinkEnabledResult);


    IsLogDownlinkEnabledResult::IsLogDownlinkEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsLogDownlinkEnabledResult::IsLogDownlinkEnabledResult(bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setBeforeEncoding(beforeEncoding);
      setAfterEncoding(afterEncoding);
    }

    IsLogDownlinkEnabledResult::IsLogDownlinkEnabledResult(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsLogDownlinkEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "BeforeEncoding", "AfterEncoding"}; 
      return names; 
    }


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
