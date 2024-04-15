#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable/Disable a multipath signal.
    ///
    /// Name    Type   Description
    /// ------- ------ ---------------------------------------------------------------
    /// Enabled bool   Enable (true) or disable (false) multipath.
    /// Id      string Unique identifier of the multipath signal to enable or disable.
    ///

    class EnableMultipath;
    typedef std::shared_ptr<EnableMultipath> EnableMultipathPtr;
    
    
    class EnableMultipath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableMultipath();

      EnableMultipath(bool enabled, const std::string& id);

      static EnableMultipathPtr create(bool enabled, const std::string& id);
      static EnableMultipathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

