#pragma once

#include <memory>
#include "command_base.h"

#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) downlink data logging in csv format
    ///
    /// Name           Type          Description
    /// -------------- ------------- ----------------------------------------------------------------------------------------------------------------------
    /// Enabled        bool          If true, files will be created during simulation. By default, the downlink files will be created after signal encoding
    /// BeforeEncoding optional bool (Optional) If true, files will be created before signal encoding. Can be used with AfterEncoding
    /// AfterEncoding  optional bool (Optional) If true, files will be created after signal encoding. Can be used with BeforeEncoding
    ///

    class EnableLogDownlink;
    typedef std::shared_ptr<EnableLogDownlink> EnableLogDownlinkPtr;
    
    
    class EnableLogDownlink : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableLogDownlink();

      EnableLogDownlink(bool enabled, const std::optional<bool>& beforeEncoding = {}, const std::optional<bool>& afterEncoding = {});

      static EnableLogDownlinkPtr create(bool enabled, const std::optional<bool>& beforeEncoding = {}, const std::optional<bool>& afterEncoding = {});
      static EnableLogDownlinkPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** beforeEncoding ****
      std::optional<bool> beforeEncoding() const;
      void setBeforeEncoding(const std::optional<bool>& beforeEncoding);


      // **** afterEncoding ****
      std::optional<bool> afterEncoding() const;
      void setAfterEncoding(const std::optional<bool>& afterEncoding);
    };
    
  }
}

