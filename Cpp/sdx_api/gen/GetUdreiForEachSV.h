#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the UDREI value transmitted by SBAS for all satellites of the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------
    /// System string "GPS" or "SBAS".
    ///

    class GetUdreiForEachSV;
    typedef std::shared_ptr<GetUdreiForEachSV> GetUdreiForEachSVPtr;
    
    
    class GetUdreiForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetUdreiForEachSV();

      GetUdreiForEachSV(const std::string& system);

      static GetUdreiForEachSVPtr create(const std::string& system);
      static GetUdreiForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

