
#include "EnableLogDownlink.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableLogDownlink
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableLogDownlink::CmdName = "EnableLogDownlink";
    const char* const EnableLogDownlink::Documentation = "Enable (or disable) downlink data logging in csv format\n"
      "\n"
      "Name           Type          Description\n"
      "-------------- ------------- ----------------------------------------------------------------------------------------------------------------------\n"
      "Enabled        bool          If true, files will be created during simulation. By default, the downlink files will be created after signal encoding\n"
      "BeforeEncoding optional bool (Optional) If true, files will be created before signal encoding. Can be used with AfterEncoding\n"
      "AfterEncoding  optional bool (Optional) If true, files will be created after signal encoding. Can be used with BeforeEncoding";
    const char* const EnableLogDownlink::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableLogDownlink);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableLogDownlink);


    EnableLogDownlink::EnableLogDownlink()
      : CommandBase(CmdName, TargetId)
    {}

    EnableLogDownlink::EnableLogDownlink(bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setBeforeEncoding(beforeEncoding);
      setAfterEncoding(afterEncoding);
    }

    EnableLogDownlinkPtr EnableLogDownlink::create(bool enabled, const Sdx::optional<bool>& beforeEncoding, const Sdx::optional<bool>& afterEncoding)
    {
      return std::make_shared<EnableLogDownlink>(enabled, beforeEncoding, afterEncoding);
    }

    EnableLogDownlinkPtr EnableLogDownlink::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableLogDownlink>(ptr);
    }

    bool EnableLogDownlink::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["BeforeEncoding"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["AfterEncoding"])
        ;

    }

    std::string EnableLogDownlink::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableLogDownlink::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "BeforeEncoding", "AfterEncoding"}; 
      return names; 
    }


    int EnableLogDownlink::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableLogDownlink::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableLogDownlink::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> EnableLogDownlink::beforeEncoding() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["BeforeEncoding"]);
    }

    void EnableLogDownlink::setBeforeEncoding(const Sdx::optional<bool>& beforeEncoding)
    {
      m_values.AddMember("BeforeEncoding", parse_json<Sdx::optional<bool>>::format(beforeEncoding, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> EnableLogDownlink::afterEncoding() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["AfterEncoding"]);
    }

    void EnableLogDownlink::setAfterEncoding(const Sdx::optional<bool>& afterEncoding)
    {
      m_values.AddMember("AfterEncoding", parse_json<Sdx::optional<bool>>::format(afterEncoding, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
