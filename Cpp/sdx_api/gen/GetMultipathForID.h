#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get multipath infos for the specified multipath ID.
    ///
    /// Name Type   Description
    /// ---- ------ --------------
    /// Id   string A multipath ID
    ///

    class GetMultipathForID;
    typedef std::shared_ptr<GetMultipathForID> GetMultipathForIDPtr;
    
    
    class GetMultipathForID : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMultipathForID();

      GetMultipathForID(const std::string& id);

      static GetMultipathForIDPtr create(const std::string& id);
      static GetMultipathForIDPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

