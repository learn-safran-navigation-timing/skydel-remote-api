#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the GPS MNAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------------------------
    /// Id   string Unique identifier automatically set by simulator
    ///

    class GetMessageModificationToGpsMNav;
    typedef std::shared_ptr<GetMessageModificationToGpsMNav> GetMessageModificationToGpsMNavPtr;
    
    
    class GetMessageModificationToGpsMNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToGpsMNav();

      GetMessageModificationToGpsMNav(const std::string& id);

      static GetMessageModificationToGpsMNavPtr create(const std::string& id);
      static GetMessageModificationToGpsMNavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

