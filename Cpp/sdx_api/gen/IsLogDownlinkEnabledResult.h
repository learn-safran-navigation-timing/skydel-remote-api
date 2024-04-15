#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogDownlinkEnabled.
    ///
    /// Name           Type          Description
    /// -------------- ------------- ----------------------------------------------------------------------------------------------------------------------
    /// Enabled        bool          If true, files will be created during simulation. By default, the downlink files will be created after signal encoding
    /// BeforeEncoding optional bool (Optional) If true, files will be created before signal encoding. Can be used with AfterEncoding
    /// AfterEncoding  optional bool (Optional) If true, files will be created after signal encoding. Can be used with BeforeEncoding
    ///

    class IsLogDownlinkEnabledResult;
    typedef std::shared_ptr<IsLogDownlinkEnabledResult> IsLogDownlinkEnabledResultPtr;
    
    
    class IsLogDownlinkEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsLogDownlinkEnabledResult();

      IsLogDownlinkEnabledResult(bool enabled, const Sdx::optional<bool>& beforeEncoding = {}, const Sdx::optional<bool>& afterEncoding = {});

      IsLogDownlinkEnabledResult(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& beforeEncoding = {}, const Sdx::optional<bool>& afterEncoding = {});

      static IsLogDownlinkEnabledResultPtr create(bool enabled, const Sdx::optional<bool>& beforeEncoding = {}, const Sdx::optional<bool>& afterEncoding = {});

      static IsLogDownlinkEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled, const Sdx::optional<bool>& beforeEncoding = {}, const Sdx::optional<bool>& afterEncoding = {});
      static IsLogDownlinkEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** beforeEncoding ****
      Sdx::optional<bool> beforeEncoding() const;
      void setBeforeEncoding(const Sdx::optional<bool>& beforeEncoding);


      // **** afterEncoding ****
      Sdx::optional<bool> afterEncoding() const;
      void setAfterEncoding(const Sdx::optional<bool>& afterEncoding);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogDownlinkEnabledResult);
  }
}

