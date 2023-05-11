#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the GPS CNAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToGpsCNav;
    typedef std::shared_ptr<GetMessageModificationToGpsCNav> GetMessageModificationToGpsCNavPtr;
    
    
    class GetMessageModificationToGpsCNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToGpsCNav();

      GetMessageModificationToGpsCNav(const std::string& id);

      static GetMessageModificationToGpsCNavPtr create(const std::string& id);
      static GetMessageModificationToGpsCNavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

