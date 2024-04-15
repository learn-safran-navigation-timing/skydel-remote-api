#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA tag size.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------
    /// TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.
    ///

    class SetOsnmaTagSize;
    typedef std::shared_ptr<SetOsnmaTagSize> SetOsnmaTagSizePtr;
    
    
    class SetOsnmaTagSize : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetOsnmaTagSize();

      SetOsnmaTagSize(int tagSize);

      static SetOsnmaTagSizePtr create(int tagSize);
      static SetOsnmaTagSizePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** tagSize ****
      int tagSize() const;
      void setTagSize(int tagSize);
    };
    
  }
}

