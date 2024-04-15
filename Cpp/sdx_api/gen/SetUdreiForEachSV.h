#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the UDREI value transmitted by SBAS for all satellites of the specified constellation.
    ///
    /// Name   Type      Description
    /// ------ --------- --------------------------------------------------------------------------------------------------------------------------
    /// System string    "GPS" or "SBAS".
    /// Udreis array int UDREI value to set for each satellite. Zero based index (index 0 => UDREI for SV ID 1, index 1 => UDREI for SV ID 2, etc).
    ///

    class SetUdreiForEachSV;
    typedef std::shared_ptr<SetUdreiForEachSV> SetUdreiForEachSVPtr;
    
    
    class SetUdreiForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetUdreiForEachSV();

      SetUdreiForEachSV(const std::string& system, const std::vector<int>& udreis);

      static SetUdreiForEachSVPtr create(const std::string& system, const std::vector<int>& udreis);
      static SetUdreiForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** udreis ****
      std::vector<int> udreis() const;
      void setUdreis(const std::vector<int>& udreis);
    };
    
  }
}

