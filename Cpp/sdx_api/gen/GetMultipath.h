#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetMultipath is deprecated since 21.3. You may use GetMultipathForID.
    /// 
    /// Get multipath infos for the specified multipath ID.
    ///
    /// Name Type   Description
    /// ---- ------ --------------
    /// Id   string A multipath ID
    ///

    class GetMultipath;
    typedef std::shared_ptr<GetMultipath> GetMultipathPtr;
    
    
    class GetMultipath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMultipath();

      GetMultipath(const std::string& id);
  
      static GetMultipathPtr create(const std::string& id);
      static GetMultipathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

