/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "parser.ypp" /* yacc.c:339  */

	#include "file/lexerDefs.h"
	#include "file/parserDefs.h"
	#include "file/parser.h"
	#include "file/write.h" // format_type(Type);

	#include "dc/File.h"
	#include "dc/DistributedType.h"
	#include "dc/NumericRange.h"
	#include "dc/NumericType.h"
	#include "dc/ArrayType.h"
	#include "dc/Struct.h"
	#include "dc/Class.h"
	#include "dc/Field.h"
	#include "dc/Method.h"
	#include "dc/Parameter.h"
	#include "dc/MolecularField.h"

	#include <unistd.h>
	#include <stdint.h> // Fixed width integer limits
	#include <math.h>   // Float INFINITY
	#include <stack>    // std::stack

	#define yyparse run_parser
	#define yylex run_lexer
	#define yyerror parser_error
	#define yywarning parser_warning
	#define yychar dcyychar
	#define yydebug dcyydebug
	#define yynerrs dcyynerrs

	// Because our token type contains objects of type string, which
	// require correct copy construction (and not simply memcpying), we
	// cannot use bison's built-in auto-stack-grow feature.  As an easy
	// solution, we ensure here that we have enough yacc stack to start
	// with, and that it doesn't ever try to grow.
	#define YYINITDEPTH 1000
	#define YYMAXDEPTH 1000

	using namespace std;
	namespace dclass   // open namespace dclass
	{


	// Parser output
	static File* parsed_file = (File*)NULL;
	static string* parsed_value = (string*)NULL;

	// Parser state
	static Class* current_class = (Class*)NULL;
	static Struct* current_struct = (Struct*)NULL;

	// Stack of distributed types for parsing values
	struct TypeAndDepth
	{
		int depth;
		const DistributedType* type;
		TypeAndDepth(const DistributedType* t, int d) : depth(d), type(t) {}
	};
	static stack<TypeAndDepth> type_stack;
	static int current_depth;

	// These two types are really common types the parser doesn't need to make new
	//     duplicates of every time a string or blob is used.
	static ArrayType* basic_string = (ArrayType*)NULL;
	static ArrayType* basic_blob = (ArrayType*)NULL;

	/* Helper functions */
	static bool check_depth();
	static void depth_error(string what);
	static void depth_error(int depth, string what);
	static string number_value(Type type, double &number);
	static string number_value(Type type, int64_t &number);
	static string number_value(Type type, uint64_t &number);

////////////////////////////////////////////////////////////////////
// Defining the interface to the parser.
////////////////////////////////////////////////////////////////////

	void init_file_parser(istream& in, const string& filename, File& file)
	{
		parsed_file = &file;
		init_file_lexer(in, filename);
	}

	void init_value_parser(istream& in, const string& source,
	                       const DistributedType* type, string& output)
	{
		parsed_value = &output;
		current_depth = 0;
		type_stack.push(TypeAndDepth(type, 0));
		init_value_lexer(in, source);
	}

	void cleanup_parser()
	{
		current_depth = 0;
		type_stack = stack<TypeAndDepth>();
		parsed_file = (File*)NULL;
		parsed_value = (string*)NULL;
	}

	int parser_error_count()
	{
		return lexer_error_count();
	}
	int parser_warning_count()
	{
		return lexer_warning_count();
	}

	void parser_error(const string &msg)
	{
		lexer_error(msg);
	}
	void parser_warning(const string &msg)
	{
		lexer_warning(msg);
	}

#line 187 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UNSIGNED_INTEGER = 258,
    SIGNED_INTEGER = 259,
    REAL = 260,
    STRING = 261,
    HEX_STRING = 262,
    IDENTIFIER = 263,
    CHAR = 264,
    START_DC_FILE = 265,
    START_DC_VALUE = 266,
    KW_DCLASS = 267,
    KW_STRUCT = 268,
    KW_FROM = 269,
    KW_IMPORT = 270,
    KW_TYPEDEF = 271,
    KW_KEYWORD = 272,
    KW_INT8 = 273,
    KW_INT16 = 274,
    KW_INT32 = 275,
    KW_INT64 = 276,
    KW_UINT8 = 277,
    KW_UINT16 = 278,
    KW_UINT32 = 279,
    KW_UINT64 = 280,
    KW_FLOAT32 = 281,
    KW_FLOAT64 = 282,
    KW_STRING = 283,
    KW_BLOB = 284,
    KW_CHAR = 285
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 264 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      42,    43,    33,     2,    34,    45,    32,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    31,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   228,   228,   229,   234,   235,   236,   237,   238,   239,
     240,   244,   248,   253,   261,   266,   275,   276,   283,   284,
     291,   295,   303,   304,   311,   356,   366,   381,   385,   386,
     394,   393,   433,   434,   438,   445,   455,   486,   487,   488,
     526,   550,   558,   557,   597,   598,   599,   633,   634,   638,
     639,   640,   641,   645,   650,   649,   664,   671,   680,   679,
     691,   690,   702,   701,   715,   722,   723,   727,   745,   749,
     753,   757,   761,   768,   794,   826,   848,   876,   899,   900,
     901,   902,   906,   910,   922,   931,   943,   950,   957,   967,
     971,   978,   988,  1001,  1002,  1003,  1004,  1009,  1008,  1022,
    1029,  1038,  1037,  1049,  1048,  1062,  1063,  1064,  1065,  1069,
    1070,  1071,  1072,  1076,  1088,  1092,  1105,  1122,  1123,  1124,
    1128,  1140,  1144,  1153,  1162,  1171,  1201,  1231,  1232,  1237,
    1236,  1273,  1274,  1282,  1281,  1318,  1319,  1320,  1324,  1331,
    1357,  1356,  1405,  1407,  1406,  1421,  1426,  1442,  1458,  1474,
    1524,  1578,  1579,  1583,  1584,  1585,  1586,  1587,  1588,  1589,
    1590,  1591,  1592,  1593,  1597,  1601,  1614
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNSIGNED_INTEGER", "SIGNED_INTEGER",
  "REAL", "STRING", "HEX_STRING", "IDENTIFIER", "CHAR", "START_DC_FILE",
  "START_DC_VALUE", "KW_DCLASS", "KW_STRUCT", "KW_FROM", "KW_IMPORT",
  "KW_TYPEDEF", "KW_KEYWORD", "KW_INT8", "KW_INT16", "KW_INT32",
  "KW_INT64", "KW_UINT8", "KW_UINT16", "KW_UINT32", "KW_UINT64",
  "KW_FLOAT32", "KW_FLOAT64", "KW_STRING", "KW_BLOB", "KW_CHAR", "';'",
  "'.'", "'*'", "','", "'/'", "'{'", "'}'", "':'", "'='", "'['", "']'",
  "'('", "')'", "'%'", "'-'", "$accept", "grammar", "file", "value",
  "import", "import_module", "import_symbols", "import_symbol_list",
  "import_alternatives", "typedef", "nonmethod_type_with_name",
  "defined_type", "keyword_decl", "keyword_decl_list", "dclass", "$@1",
  "class_inheritance", "class_parents", "defined_class", "class_fields",
  "class_field", "dstruct", "$@2", "struct_fields", "struct_field",
  "named_field", "unnamed_field", "$@3", "field_with_name",
  "field_with_name_as_array", "field_with_name_and_default", "$@4", "$@5",
  "$@6", "method_as_field", "nonmethod_type", "nonmethod_type_no_array",
  "type_with_array", "molecular", "defined_field", "builtin_array_type",
  "numeric_type", "numeric_token_only", "numeric_with_range",
  "numeric_with_modulus", "numeric_with_divisor", "method", "method_body",
  "parameter", "$@7", "param_with_name", "param_with_name_as_array",
  "param_with_name_and_default", "$@8", "$@9", "numeric_range",
  "array_range", "char_or_uint", "small_unsigned_integer",
  "small_negative_integer", "number", "char_or_number", "type_value",
  "method_value", "$@10", "parameter_values", "struct_value", "$@11",
  "field_values", "array_value", "$@12", "element_values", "$@13",
  "array_expansion", "array_type_token", "numeric_type_token",
  "keyword_list", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    59,    46,    42,    44,    47,   123,   125,    58,    61,
      91,    93,    40,    41,    37,    45
};
# endif

#define YYPACT_NINF -184

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-184)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     100,  -184,    14,    30,    49,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,     5,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,    44,    52,    62,    62,   205,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,    14,  -184,    33,    38,  -184,  -184,  -184,
      17,    41,    51,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,    66,   107,
    -184,  -184,    68,    92,    40,   -11,    57,  -184,    93,  -184,
     125,  -184,  -184,  -184,    -9,   101,   103,   104,   105,   106,
    -184,   -12,  -184,  -184,    43,   102,   109,    15,    62,   133,
      50,  -184,    50,    50,   143,    84,    94,   143,    94,   143,
      50,  -184,    14,  -184,   143,   143,   143,   143,   143,  -184,
    -184,    38,  -184,   135,   111,  -184,  -184,  -184,  -184,   115,
      41,    41,  -184,  -184,  -184,   110,    12,  -184,  -184,   112,
     113,  -184,  -184,  -184,  -184,  -184,   129,  -184,     6,  -184,
    -184,  -184,  -184,  -184,   130,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,    33,  -184,  -184,   116,  -184,  -184,   140,  -184,
      62,  -184,  -184,    50,  -184,  -184,  -184,  -184,    84,  -184,
    -184,  -184,   135,   178,  -184,   114,  -184,  -184,  -184,   121,
    -184,  -184,    73,   136,  -184,   137,    19,    41,  -184,  -184,
    -184,    29,  -184,  -184,   124,  -184,   144,    99,  -184,    47,
    -184,  -184,    50,  -184,   138,  -184,   171,  -184,   173,  -184,
     171,  -184,   145,   174,  -184,    91,   146,  -184,   205,  -184,
      38,   142,    38,  -184,    38,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,    50,  -184,  -184,  -184,  -184,  -184,    38,  -184,
      38,    38,   147,    38,  -184,  -184,  -184,  -184,  -184
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   166,   166,     0,     2,     4,   123,   122,   124,   125,
     126,   133,   140,   129,     3,    12,    13,   128,   127,    11,
       1,     0,     0,     0,     0,     0,   166,     5,     8,     9,
      10,     6,     7,     0,   139,     0,     0,    30,    42,    22,
       0,    16,    14,    26,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   151,   152,   153,    24,    67,     0,
      65,    66,    69,    68,    78,    79,    80,    81,    76,    82,
      27,    28,   135,   136,     0,   123,   122,   124,   125,   126,
     145,     0,   142,   131,     0,   166,     0,     0,     0,     0,
     166,    25,   166,   166,     0,   166,     0,     0,     0,     0,
     166,    29,     0,   134,     0,     0,     0,     0,     0,   143,
     141,     0,   130,     0,     0,    32,   166,    19,    15,    18,
      20,    17,    23,   115,   113,     0,   110,   114,   109,     0,
       0,    86,   117,   118,   119,   120,     0,   121,   106,   105,
      84,    87,    85,    88,     0,   137,   138,   147,   146,   148,
     149,   150,     0,   132,    36,    33,    34,   166,     0,    44,
       0,    71,   116,     0,   112,    72,    70,    83,     0,   108,
      77,   144,     0,     0,    37,    26,    45,    43,    56,     0,
      47,    48,    49,    50,    51,    52,    53,    21,   111,   107,
      35,    26,    38,    31,     0,   166,    41,     0,    64,     0,
      46,    58,   166,    60,     0,    54,     0,    39,    40,   164,
       0,    89,    96,    65,    91,    93,    94,    95,     0,    90,
       0,     0,     0,    62,     0,    75,    73,   165,    74,    97,
      99,   101,   166,   103,    92,    59,    57,    61,     0,    55,
       0,     0,     0,     0,    63,    98,   102,   100,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,  -184,  -184,   163,  -184,  -184,   -81,  -184,
     164,  -184,  -184,  -184,  -184,  -184,  -184,  -184,    18,  -184,
    -184,  -184,  -184,  -184,  -184,    20,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -150,  -183,  -184,  -184,   -19,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   -26,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,   -88,    31,    -3,  -184,
     -83,    42,    -2,   -30,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,    59,  -184,  -184,  -184,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    14,    28,    40,   118,   119,    41,    29,
     178,    58,    30,    70,    31,    85,   114,   155,   156,   173,
     194,    32,    86,   158,   179,   180,   181,   224,   182,   183,
     184,   220,   222,   238,   185,    59,    60,    61,   196,   226,
      62,    63,    64,    65,    66,    67,   198,   199,   214,   240,
     215,   216,   217,   241,   243,   136,   125,   126,   127,   164,
     137,   138,    80,    16,    36,    84,    17,    33,    74,    18,
      35,    81,   152,    82,    68,    69,   208,   128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,     5,    19,    73,   129,   130,   120,   121,   186,   132,
     133,   134,   144,   140,   213,   142,   162,     6,     7,     8,
       9,    10,   109,    39,    97,   102,    71,    91,   103,   110,
      20,    72,    87,    98,    83,   213,    75,    76,    77,    78,
      79,     6,     7,     8,     9,    10,    34,   212,   117,    88,
      11,   168,    37,   123,    12,   169,    13,   163,   205,   124,
      38,    21,    22,    23,    24,    25,    26,   206,   212,    11,
      39,   197,   146,    12,    11,    94,    89,   111,    12,   187,
      27,   218,    95,    88,    96,   115,   112,   132,   133,   134,
     219,   131,    99,   135,   141,   139,   143,   132,   133,   134,
     145,   147,   148,   149,   150,   151,    90,    43,    92,   153,
       1,     2,   201,   202,   221,    91,   159,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
     231,   232,    93,   101,   104,   100,   105,   106,   107,   108,
     113,   122,   211,   154,   242,   116,   123,   157,   175,   160,
     172,   161,   200,   165,   166,   207,   197,   174,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,   176,   167,   170,   223,   203,   204,   177,   210,   225,
      13,   227,   230,   236,   229,   233,   191,    42,   247,    57,
     190,   228,   234,   195,   188,   209,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   192,
     189,   171,     0,    43,     0,   193,     0,     0,   235,     0,
     237,     0,   239,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,   244,     0,   245,   246,
       0,   248
};

static const yytype_int16 yycheck[] =
{
       2,     1,     2,    33,    92,    93,    87,    88,   158,     3,
       4,     5,   100,    96,   197,    98,     4,     3,     4,     5,
       6,     7,    34,     8,    35,    34,    26,     8,    37,    41,
       0,    33,    15,    44,    36,   218,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    41,   197,    33,    32,
      36,    45,     8,     3,    40,   138,    42,    45,    39,     9,
       8,    12,    13,    14,    15,    16,    17,    38,   218,    36,
       8,    42,   102,    40,    36,    35,    35,    34,    40,   160,
      31,    34,    42,    32,    44,    85,    43,     3,     4,     5,
      43,    94,    35,     9,    97,    95,    99,     3,     4,     5,
     102,   104,   105,   106,   107,   108,    40,     8,    40,   111,
      10,    11,    39,    40,   202,     8,   116,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      39,    40,    40,     8,    33,    42,    33,    33,    33,    33,
      38,     8,    43,     8,   232,    36,     3,    36,     8,    34,
      34,    41,    31,    41,    41,    31,    42,   157,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    43,    43,   204,    39,    39,    37,    34,     8,
      42,     8,     8,    41,    39,    39,     8,    24,    41,    25,
     172,   210,   218,   173,   163,   195,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     168,   152,    -1,     8,    -1,    37,    -1,    -1,   220,    -1,
     222,    -1,   224,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,   238,    -1,   240,   241,
      -1,   243
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    47,    48,   123,     3,     4,     5,     6,
       7,    36,    40,    42,    49,   108,   109,   112,   115,   123,
       0,    12,    13,    14,    15,    16,    17,    31,    50,    55,
      58,    60,    67,   113,    41,   116,   110,     8,     8,     8,
      51,    54,    51,     8,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    56,    57,    81,
      82,    83,    86,    87,    88,    89,    90,    91,   120,   121,
      59,   123,   108,   109,   114,     3,     4,     5,     6,     7,
     108,   117,   119,   108,   111,    61,    68,    15,    32,    35,
      40,     8,    40,    40,    35,    42,    44,    35,    44,    35,
      42,     8,    34,    37,    33,    33,    33,    33,    33,    34,
      41,    34,    43,    38,    62,   123,    36,    33,    52,    53,
      54,    54,     8,     3,     9,   102,   103,   104,   123,   102,
     102,   104,     3,     4,     5,     9,   101,   106,   107,   123,
     106,   104,   106,   104,   102,   108,   109,   104,   104,   104,
     104,   104,   118,   108,     8,    63,    64,    36,    69,   123,
      34,    41,     4,    45,   105,    41,    41,    43,    45,   106,
      43,   119,    34,    65,   123,     8,    31,    37,    56,    70,
      71,    72,    74,    75,    76,    80,    81,    54,   103,   107,
      64,     8,    31,    37,    66,    71,    84,    42,    92,    93,
      31,    39,    40,    39,    39,    39,    38,    31,   122,   123,
      34,    43,    81,    82,    94,    96,    97,    98,    34,    43,
      77,   102,    78,   109,    73,     8,    85,     8,    85,    39,
       8,    39,    40,    39,    94,   108,    41,   108,    79,   108,
      95,    99,   102,   100,   108,   108,   108,    41,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    57,    58,    59,    59,
      61,    60,    62,    62,    63,    63,    64,    65,    65,    65,
      66,    66,    68,    67,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    72,    73,    72,    74,    75,    77,    76,
      78,    76,    79,    76,    80,    81,    81,    82,    82,    82,
      83,    83,    83,    84,    84,    85,    86,    86,    87,    87,
      87,    87,    88,    89,    90,    90,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    94,    96,
      97,    99,    98,   100,    98,   101,   101,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   105,   106,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   110,
     109,   111,   111,   113,   112,   114,   114,   114,   114,   115,
     116,   115,   117,   118,   117,   119,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   122,   122,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     2,     4,     1,     3,     1,     1,
       1,     3,     1,     3,     2,     2,     1,     2,     1,     2,
       0,     7,     1,     2,     1,     3,     1,     1,     2,     3,
       2,     1,     0,     6,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     4,     0,     4,
       0,     4,     0,     5,     2,     1,     1,     1,     1,     1,
       4,     4,     4,     3,     3,     1,     1,     4,     1,     1,
       1,     1,     1,     4,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     1,     1,     0,     4,     2,
       4,     0,     4,     0,     4,     1,     1,     3,     2,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     3,     0,     4,     1,     1,     3,     3,     2,
       0,     4,     1,     0,     4,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 11:
#line 245 "parser.ypp" /* yacc.c:1646  */
    {
		parsed_value->clear();
	}
#line 1545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 249 "parser.ypp" /* yacc.c:1646  */
    {
		parsed_value->assign((yyvsp[0].str));
		if(!type_stack.empty()) depth_error(0, "type");
	}
#line 1554 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 254 "parser.ypp" /* yacc.c:1646  */
    {
		parsed_value->assign((yyvsp[0].str));
		if(!type_stack.empty()) depth_error(0, "method");
	}
#line 1563 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 262 "parser.ypp" /* yacc.c:1646  */
    {
		Import* import = new Import((yyvsp[0].str));
		parsed_file->add_import(import);
	}
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 267 "parser.ypp" /* yacc.c:1646  */
    {
		Import* import = new Import((yyvsp[-2].str));
		import->symbols.assign((yyvsp[0].strings).begin(), (yyvsp[0].strings).end());
		parsed_file->add_import(import);
	}
#line 1582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 275 "parser.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 277 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-2].str) + string(".") + (yyvsp[0].str);
	}
#line 1596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 283 "parser.ypp" /* yacc.c:1646  */
    { (yyval.strings) = (yyvsp[0].strings); }
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 285 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.strings) = vector<string>();
	}
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 292 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.strings) = vector<string>(1, (yyvsp[0].str));
	}
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 296 "parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-2].strings).push_back((yyvsp[0].str));
		(yyval.strings) = (yyvsp[-2].strings);
	}
#line 1627 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 303 "parser.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 1633 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 305 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-2].str) + string("/") + (yyvsp[0].str);
	}
#line 1641 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 312 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].nametype).type == (DistributedType*)NULL)
		{
			// TODO: Figure out if we need to do anything here
			break;
		}

		// Set the type's typedef
		(yyvsp[0].nametype).type->set_alias((yyvsp[0].nametype).name);

		bool type_added	= parsed_file->add_typedef((yyvsp[0].nametype).name, (yyvsp[0].nametype).type);
		if(!type_added)
		{
			// Lets be really descriptive about why this failed
			DistributedType* dtype = parsed_file->get_type_by_name((yyvsp[0].nametype).name);
			if(dtype == (DistributedType*)NULL)
			{
				parser_error("Unknown error adding typedef to file.");
				break;
			}

			Struct* dstruct = dtype->as_struct();
			if(dstruct == (Struct*)NULL)
			{
				parser_error("Cannot add 'typedef " + (yyvsp[0].nametype).name
				             + "' to file because a typedef was already declared with that name.");
				break;
			}

			if(dstruct->as_class())
			{
				parser_error("Cannot add 'typedef " + (yyvsp[0].nametype).name
				             + "' to file because a class was already declared with that name.");
			}
			else
			{
				parser_error("Cannot add 'typedef " + (yyvsp[0].nametype).name
				             + "' to file because a struct was already declared with that name.");
			}
		}
	}
#line 1687 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 357 "parser.ypp" /* yacc.c:1646  */
    {
		TokenType::NameType nt;
		nt.type = (yyvsp[-1].u.dtype);
		nt.name = (yyvsp[0].str);
		(yyval.nametype) = nt;
	}
#line 1698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 367 "parser.ypp" /* yacc.c:1646  */
    {
		DistributedType* dtype = parsed_file->get_type_by_name((yyvsp[0].str));
		if(dtype == (DistributedType*)NULL)
		{
			parser_error("Type '" + string((yyvsp[0].str)) + "' has not been declared.");
			(yyval.u.dtype) = NULL;
			break;
		}

		(yyval.u.dtype) = dtype;
	}
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 387 "parser.ypp" /* yacc.c:1646  */
    {
		parsed_file->add_keyword((yyvsp[0].str));
	}
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 394 "parser.ypp" /* yacc.c:1646  */
    {
		current_class = new Class(parsed_file, (yyvsp[0].str));
	}
#line 1730 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 398 "parser.ypp" /* yacc.c:1646  */
    {
		bool class_added = parsed_file->add_class(current_class);
		if(!class_added)
		{
			// Lets be really descriptive about why this failed
			DistributedType* dtype = parsed_file->get_type_by_name(current_class->get_name());
			if(dtype == (DistributedType*)NULL)
			{
				parser_error("Unknown error adding class to file.");
				break;
			}

			Struct* dstruct = dtype->as_struct();
			if(dstruct == (Struct*)NULL)
			{
				parser_error("Cannot add 'dclass " + current_class->get_name()
				             + "' to file because a typedef was already declared with that name.");
				break;
			}

			if(dstruct->as_class())
			{
				parser_error("Cannot add 'dclass " + current_class->get_name()
				             + "' to file because a class was already declared with that name.");
			}
			else
			{
				parser_error("Cannot add 'dclass " + current_class->get_name()
				             + "' to file because a struct was already declared with that name.");
			}
		}
	}
#line 1767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 439 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].u.dclass) != (Class*)NULL)
		{
			current_class->add_parent((yyvsp[0].u.dclass));
		}
	}
#line 1778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 446 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].u.dclass) != (Class*)NULL)
		{
			current_class->add_parent((yyvsp[0].u.dclass));
		}
	}
#line 1789 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 456 "parser.ypp" /* yacc.c:1646  */
    {
		DistributedType* dtype = parsed_file->get_type_by_name((yyvsp[0].str));
		if(dtype == (DistributedType*)NULL)
		{
			parser_error("'dclass " + string((yyvsp[0].str)) + "' has not been declared.");
			(yyval.u.dclass) = NULL;
			break;
		}

		Struct* dstruct = dtype->as_struct();
		if(dstruct == (Struct*)NULL)
		{
			parser_error("class cannot inherit from non-class type '" + string((yyvsp[0].str)) + "'.");
			(yyval.u.dclass) = NULL;
			break;
		}

		Class* dclass = dstruct->as_class();
		if(dclass == (Class*)NULL)
		{
			parser_error("class cannot inherit from struct type '" + string((yyvsp[0].str)) + "'.");
			(yyval.u.dclass) = NULL;
			break;
		}

		(yyval.u.dclass) = dclass;
	}
#line 1821 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 489 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-1].u.dfield) == (Field*)NULL)
		{
			// Ignore this field, it should have already generated a parser error
			break;
		}

		bool field_added = current_class->add_field((yyvsp[-1].u.dfield));
		if(!field_added)
		{
			// Lets be really descriptive about why this failed
			if(current_class->get_field_by_name((yyvsp[-1].u.dfield)->get_name()))
			{
				parser_error("Cannot add field '" + (yyvsp[-1].u.dfield)->get_name()
				             + "', a field with that name already exists in 'dclass "
				             + current_class->get_name() + "'.");
			}
			else if(current_class->get_name() == (yyvsp[-1].u.dfield)->get_name())
			{
				if((yyvsp[-1].u.dfield)->as_molecular())
				{
					parser_error("Cannot use a molecular field as a constructor.");
				}
				else
				{
					parser_error("The constructor must be the first field in the class.");
				}
			}
			else
			{
				parser_error("Unknown error adding field to class.");
			}
		}
	}
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 527 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-1].u.dfield) == (Field*)NULL)
		{
			// Ignore this field, it should have already generated a parser error
			(yyval.u.dfield) = NULL;
			break;
		}

		if((yyvsp[-1].u.dfield)->get_name().empty())
		{
			parser_error("An unnamed field can't be defined in a class.");
			(yyval.u.dfield) = NULL;
			break;
		}

		// Add the keywords to the class
		for(auto it = (yyvsp[0].strings).begin(); it != (yyvsp[0].strings).end(); ++it)
		{
			(yyvsp[-1].u.dfield)->add_keyword(*it);
		}

		(yyval.u.dfield) = (yyvsp[-1].u.dfield);
	}
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 551 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dfield) = (Field*)(yyvsp[0].u.dmolecule);
	}
#line 1896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 558 "parser.ypp" /* yacc.c:1646  */
    {
		current_struct = new Struct(parsed_file, (yyvsp[0].str));
	}
#line 1904 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 562 "parser.ypp" /* yacc.c:1646  */
    {
		bool struct_added = parsed_file->add_struct(current_struct);
		if(!struct_added)
		{
			// Lets be really descriptive about why this failed
			DistributedType* dtype = parsed_file->get_type_by_name(current_struct->get_name());
			if(dtype == (DistributedType*)NULL)
			{
				parser_error("Unknown error adding struct to file.");
				break;
			}

			Struct* dstruct = dtype->as_struct();
			if(dstruct == (Struct*)NULL)
			{
				parser_error("Cannot add 'struct " + current_struct->get_name()
				             + "' to file because a typedef was already declared with that name.");
				break;
			}

			if(dstruct->as_class())
			{
				parser_error("Cannot add 'struct " + current_struct->get_name()
				             + "' to file because a class was already declared with that name.");
			}
			else
			{
				parser_error("Cannot add 'struct " + current_struct->get_name()
				             + "' to file because a struct was already declared with that name.");
			}
		}
	}
#line 1941 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 600 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-1].u.dfield) == (Field*)NULL)
		{
			// Ignore this field, it should have already generated a parser error
			break;
		}

		if(!current_struct->add_field((yyvsp[-1].u.dfield)))
		{
			// Lets be really descriptive about why this failed
			if(current_struct->get_field_by_name((yyvsp[-1].u.dfield)->get_name()))
			{
				parser_error("Cannot add field '" + (yyvsp[-1].u.dfield)->get_name()
				             + "', a field with that name already exists in 'struct "
				             + current_struct->get_name() + "'.");
			}
			else if(current_struct->get_name() == (yyvsp[-1].u.dfield)->get_name())
			{
				parser_error("A constructor can't be defined in a struct.");
			}
			else if((yyvsp[-1].u.dfield)->get_type()->as_method())
			{
				parser_error("A method can't be defined in a struct.");
			}
			else
			{
				parser_error("Unknown error adding field to struct.");
			}
		}
	}
#line 1976 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 646 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dfield) = new Field((yyvsp[0].u.dtype));
	}
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 650 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].u.dtype), 0));
	}
#line 1993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 655 "parser.ypp" /* yacc.c:1646  */
    {
		Field* field = new Field((yyvsp[-3].u.dtype));
		if(!type_stack.empty()) depth_error(0, "unnamed field");
		field->set_default_value((yyvsp[0].str));
		(yyval.u.dfield) = field;
	}
#line 2004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 665 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dfield) = new Field((yyvsp[0].nametype).type, (yyvsp[0].nametype).name);
	}
#line 2012 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 672 "parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-3].u.dfield)->set_type(new ArrayType((yyvsp[-3].u.dfield)->get_type(), (yyvsp[-1].range)));
		(yyval.u.dfield) = (yyvsp[-3].u.dfield);
	}
#line 2021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 680 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].u.dfield)->get_type(), 0));
	}
#line 2030 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 685 "parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "field '" + (yyvsp[-3].u.dfield)->get_name() + "'");
		(yyvsp[-3].u.dfield)->set_default_value((yyvsp[0].str));
		(yyval.u.dfield) = (yyvsp[-3].u.dfield);
	}
#line 2040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 691 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].u.dfield)->get_type(), 0));
	}
#line 2049 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 696 "parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "field '" + (yyvsp[-3].u.dfield)->get_name() + "'");
		(yyvsp[-3].u.dfield)->set_default_value((yyvsp[0].str));
		(yyval.u.dfield) = (yyvsp[-3].u.dfield);
	}
#line 2059 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 702 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-2].u.dfield)->get_type(), 0));
	}
#line 2068 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 707 "parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "method");
		(yyvsp[-4].u.dfield)->set_default_value((yyvsp[-2].str));
		(yyval.u.dfield) = (yyvsp[-4].u.dfield);
	}
#line 2078 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 716 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dfield) = new Field((yyvsp[0].u.dmethod), (yyvsp[-1].str));
	}
#line 2086 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 728 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].u.dtype) == (DistributedType*)NULL)
		{
			// defined_type should have output an error, pass NULL upstream
			(yyval.u.dtype) = NULL;
			break;
		}

		if((yyvsp[0].u.dtype)->get_type() == T_METHOD)
		{
			parser_error("Cannot use a method type here.");
			(yyval.u.dtype) = NULL;
			break;
		}

		(yyval.u.dtype) = (yyvsp[0].u.dtype);
	}
#line 2108 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 746 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dtype) = (DistributedType*)(yyvsp[0].u.dnumeric);
	}
#line 2116 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 754 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dtype) = new ArrayType((yyvsp[-3].u.dnumeric), (yyvsp[-1].range));
	}
#line 2124 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 758 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dtype) = new ArrayType((yyvsp[-3].u.dtype), (yyvsp[-1].range));
	}
#line 2132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 762 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dtype) = new ArrayType((yyvsp[-3].u.dtype), (yyvsp[-1].range));
	}
#line 2140 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 769 "parser.ypp" /* yacc.c:1646  */
    {
		MolecularField* mol = new MolecularField(current_class, (yyvsp[-2].str));
		if((yyvsp[0].u.dfield) == (Field*)NULL)
		{
			// Ignore this field, it should have already generated an error
			(yyval.u.dmolecule) = mol;
			break;
		}

		bool field_added = mol->add_field((yyvsp[0].u.dfield));
		if(!field_added)
		{
			if((yyvsp[0].u.dfield)->as_molecular())
			{
				parser_error("Cannot add molecular '" + (yyvsp[0].u.dfield)->get_name() + "' to a molecular field.");
			}
			else
			{
				parser_error("Unkown error adding field " + (yyvsp[0].u.dfield)->get_name() + " to molecular '"
				             + (yyvsp[-2].str) + "'.");
			}
		}

		(yyval.u.dmolecule) = mol;
	}
#line 2170 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 795 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].u.dfield) == (Field*)NULL)
		{
			// Ignore this field, it should have already generated an error
			(yyval.u.dmolecule) = (yyvsp[-2].u.dmolecule);
			break;
		}

		bool field_added = (yyvsp[-2].u.dmolecule)->add_field((yyvsp[0].u.dfield));
		if(!field_added)
		{
			if((yyvsp[0].u.dfield)->as_molecular())
			{
				parser_error("Cannot add molecular '" + (yyvsp[0].u.dfield)->get_name() + "' to a molecular field.");
			}
			else if(!(yyvsp[-2].u.dmolecule)->has_matching_keywords(*(yyvsp[0].u.dfield)))
			{
				parser_error("Mismatched keywords in molecular between " +
					(yyvsp[-2].u.dmolecule)->get_field(0)->get_name() + " and " + (yyvsp[0].u.dfield)->get_name() + ".");
			}
			else
			{
				parser_error("Unkown error adding field " + (yyvsp[0].u.dfield)->get_name() + " to molecular '"
				             + (yyvsp[-2].u.dmolecule)->get_name() + "'.");
			}
		}

		(yyval.u.dmolecule) = (yyvsp[-2].u.dmolecule);
	}
#line 2204 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 827 "parser.ypp" /* yacc.c:1646  */
    {
		if(!current_class)
		{
			parser_error("Field '" + (yyvsp[0].str) + "' not defined in current class.");
			(yyval.u.dfield) = NULL;
			break;
		}

		Field *field = current_class->get_field_by_name((yyvsp[0].str));
		if(field == (Field*)NULL)
		{
			parser_error("Field '" + (yyvsp[0].str) + "' not defined in current class.");
			(yyval.u.dfield) = NULL;
			break;
		}

		(yyval.u.dfield) = field;
	}
#line 2227 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 849 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].u.type) == T_STRING)
		{
			if(basic_string == NULL)
			{
				basic_string = new ArrayType(new NumericType(T_CHAR));
				basic_string->set_alias("string");
			}

			(yyval.u.dtype) = basic_string;
		}
		else if((yyvsp[0].u.type) == T_BLOB)
		{
			if(basic_blob == NULL)
			{
				basic_blob = new ArrayType(new NumericType(T_UINT8));
				basic_blob->set_alias("blob");
			}

			(yyval.u.dtype) = basic_blob;
		}
		else
		{
			parser_error("Found builtin ArrayType not handled by parser.");
			(yyval.u.dtype) = NULL;
		}
	}
#line 2259 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 877 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[-3].u.type) == T_STRING)
		{
			ArrayType* arr = new ArrayType(new NumericType(T_CHAR), (yyvsp[-1].range));
			arr->set_alias("string");
			(yyval.u.dtype) = arr;
		}
		else if((yyvsp[-3].u.type) == T_BLOB)
		{
			ArrayType* arr = new ArrayType(new NumericType(T_UINT8), (yyvsp[-1].range));
			arr->set_alias("blob");
			(yyval.u.dtype) = arr;
		}
		else
		{
			parser_error("Found builtin ArrayType not handled by parser.");
			(yyval.u.dtype) = NULL;
		}
	}
#line 2283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 906 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.dnumeric) = new NumericType((yyvsp[0].u.type)); }
#line 2289 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 911 "parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-3].u.dnumeric)->set_range((yyvsp[-1].range)))
		{
			parser_error("Invalid range for type.");
		}

		(yyval.u.dnumeric) = (yyvsp[-3].u.dnumeric);
	}
#line 2302 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 923 "parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].u.dnumeric)->set_modulus((yyvsp[0].u.real)))
		{
			parser_error("Invalid modulus for type.");
		}

		(yyval.u.dnumeric) = (yyvsp[-2].u.dnumeric);
	}
#line 2315 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 932 "parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].u.dnumeric)->set_modulus((yyvsp[0].u.real)))
		{
			parser_error("Invalid modulus for type.");
		}

		(yyval.u.dnumeric) = (yyvsp[-2].u.dnumeric);
	}
#line 2328 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 944 "parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].u.dnumeric)->set_divisor((yyvsp[0].u.uint32)))
		{
			parser_error("Invalid divisor for type.");
		}
	}
#line 2339 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 951 "parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].u.dnumeric)->set_divisor((yyvsp[0].u.uint32)))
		{
			parser_error("Invalid divisor for type.");
		}
	}
#line 2350 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 958 "parser.ypp" /* yacc.c:1646  */
    {
		if(!(yyvsp[-2].u.dnumeric)->set_divisor((yyvsp[0].u.uint32)))
		{
			parser_error("Invalid divisor for type.");
		}
	}
#line 2361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 968 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dmethod) = new Method();
	}
#line 2369 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 972 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dmethod) = (yyvsp[-1].u.dmethod);
	}
#line 2377 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 979 "parser.ypp" /* yacc.c:1646  */
    {
		Method* fn = new Method();
		bool param_added = fn->add_parameter((yyvsp[0].u.dparam));
		if(!param_added)
		{
			parser_error("Unknown error adding parameter to method.");
		}
		(yyval.u.dmethod) = fn;
	}
#line 2391 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 989 "parser.ypp" /* yacc.c:1646  */
    {
		bool param_added = (yyvsp[-2].u.dmethod)->add_parameter((yyvsp[0].u.dparam));
		if(!param_added)
		{
			parser_error("Cannot add parameter '" + (yyvsp[0].u.dparam)->get_name()
			             + "', a parameter with that name is already used in this method.");
		}
		(yyval.u.dmethod) = (yyvsp[-2].u.dmethod);
	}
#line 2405 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1005 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dparam) = new Parameter((yyvsp[0].u.dtype));
	}
#line 2413 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1009 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].u.dtype),0));
	}
#line 2422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1014 "parser.ypp" /* yacc.c:1646  */
    {
		Parameter* param = new Parameter((yyvsp[-3].u.dtype));
		if(!type_stack.empty()) depth_error(0, "type");
		param->set_default_value((yyvsp[0].str));
		(yyval.u.dparam) = param;
	}
#line 2433 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1023 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.u.dparam) = new Parameter((yyvsp[-1].u.dtype), (yyvsp[0].str));
	}
#line 2441 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1030 "parser.ypp" /* yacc.c:1646  */
    {
		(yyvsp[-3].u.dparam)->set_type(new ArrayType((yyvsp[-3].u.dparam)->get_type(), (yyvsp[-1].range)));
		(yyval.u.dparam) = (yyvsp[-3].u.dparam);
	}
#line 2450 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1038 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].u.dparam)->get_type(), 0));
	}
#line 2459 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1043 "parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "parameter '" + (yyvsp[-3].u.dparam)->get_name() + "'");
		(yyvsp[-3].u.dparam)->set_default_value((yyvsp[0].str));
		(yyval.u.dparam) = (yyvsp[-3].u.dparam);
	}
#line 2469 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1049 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth = 0;
		type_stack.push(TypeAndDepth((yyvsp[-1].u.dparam)->get_type(), 0));
	}
#line 2478 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1054 "parser.ypp" /* yacc.c:1646  */
    {
		if(!type_stack.empty()) depth_error(0, "parameter '" + (yyvsp[-3].u.dparam)->get_name() + "'");
		(yyvsp[-3].u.dparam)->set_default_value((yyvsp[0].str));
		(yyval.u.dparam) = (yyvsp[-3].u.dparam);
	}
#line 2488 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1062 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange(); }
#line 2494 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1063 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[0].u.real), (yyvsp[0].u.real)); }
#line 2500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1064 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[-2].u.real), (yyvsp[0].u.real)); }
#line 2506 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1065 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[-1].u.real), (yyvsp[0].u.real)); }
#line 2512 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1069 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange(); }
#line 2518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1070 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[0].u.uint32), (yyvsp[0].u.uint32)); }
#line 2524 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1071 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[-2].u.uint32), (yyvsp[0].u.uint32)); }
#line 2530 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1072 "parser.ypp" /* yacc.c:1646  */
    { (yyval.range) = NumericRange((yyvsp[-1].u.uint32), (yyvsp[0].u.uint32)); }
#line 2536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1077 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].str).length() != 1)
		{
			parser_error("Single character required.");
			(yyval.u.uint32) = 0;
		}
		else
		{
			(yyval.u.uint32) = (unsigned char)(yyvsp[0].str)[0];
		}
	}
#line 2552 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1093 "parser.ypp" /* yacc.c:1646  */
    {
		unsigned int num = (unsigned int)(yyvsp[0].u.uint64);
		if(num != (yyvsp[0].u.uint64))
		{
			parser_error("Number out of range.");
			(yyval.u.uint32) = 1;
		}
		(yyval.u.uint32) = num;
	}
#line 2566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1106 "parser.ypp" /* yacc.c:1646  */
    {
		int num = (unsigned int) -(yyvsp[0].u.int64);
		if((yyvsp[0].u.int64) >= 0)
		{
			parser_error("Syntax error while parsing small_negative_integer.");
		}
		else if(num != -(yyvsp[0].u.int64))
		{
			parser_error("Number out of range.");
			(yyval.u.uint32) = 1;
		}
		(yyval.u.uint32) = num;
	}
#line 2584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1122 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.real) = (double)(yyvsp[0].u.uint64); }
#line 2590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1123 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.real) = (double)(yyvsp[0].u.int64); }
#line 2596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1129 "parser.ypp" /* yacc.c:1646  */
    {
		if((yyvsp[0].str).length() != 1)
		{
			parser_error("Single character required.");
			(yyval.u.real) = 0;
		}
		else
		{
			(yyval.u.real) = (double)(unsigned char)(yyvsp[0].str)[0];
		}
	}
#line 2612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1145 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("signed integer");

		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Remove numeric type from stack

		(yyval.str) = number_value(dtype->get_type(), (yyvsp[0].u.int64));
	}
#line 2625 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1154 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("unsigned integer");

		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Remove numeric type from stack

		(yyval.str) = number_value(dtype->get_type(), (yyvsp[0].u.uint64));
	}
#line 2638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1163 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("floating point");

		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Remove numeric type from stack

		(yyval.str) = number_value(dtype->get_type(), (yyvsp[0].u.real));
	}
#line 2651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1172 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("string");

		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Remove string type from stack

		if(dtype->get_type() == T_STRING)
		{
			if((yyvsp[0].str).length() != dtype->get_size())
			{
				parser_error("Value for fixed-length string has incorrect length.");
			}

			(yyval.str) = (yyvsp[0].str);
		}
		else if(dtype->get_type() == T_VARSTRING)
		{
			// TODO: Check for range limits
			// Prepend length tag
			sizetag_t length = (yyvsp[0].str).length();
			(yyval.str) = string((char*)&length, sizeof(sizetag_t)) + (yyvsp[0].str);
		}
		else
		{
			parser_error("Cannot use string value for non-string type '"
			             + format_type(dtype->get_type()) + "'.");
			(yyval.str) = (yyvsp[0].str);
		}
	}
#line 2685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1202 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("hex-string");

		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Remove type from stack

		if(dtype->get_type() == T_BLOB)
		{
			if((yyvsp[0].str).length() != dtype->get_size())
			{
				parser_error("Value for fixed-length blob has incorrect length.");
			}

			(yyval.str) = (yyvsp[0].str);
		}
		else if(dtype->get_type() == T_VARBLOB)
		{
			// TODO: Check for range limits
			// Prepend length tag
			sizetag_t length = (yyvsp[0].str).length();
			(yyval.str) = string((char*)&length, sizeof(sizetag_t)) + (yyvsp[0].str);
		}
		else
		{
			parser_error("Cannot use hex value for non-blob type '"
			             + format_type(dtype->get_type()) + "'.");
			(yyval.str) = (yyvsp[0].str);
		}
	}
#line 2719 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1237 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("method");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype->as_method())
		{
			current_depth++;
			const Method* method = dtype->as_method();

			size_t num_params = method->get_num_parameters();
			for(unsigned int i = 1; i <= num_params; ++i)
			{
				// Reverse iteration
				const Parameter* param = method->get_parameter(num_params-i);
				// Add parameter types to stack such that the first is on top
				type_stack.push(TypeAndDepth(param->get_type(), current_depth));
			}
		}
		else
		{
			parser_error("Cannot use method-value for non-method type '"
			             + format_type(dtype->get_type()) + "'.");
		}
	}
#line 2748 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1262 "parser.ypp" /* yacc.c:1646  */
    {
		if(type_stack.top().type->as_method())
		{
			current_depth--;
		}
		type_stack.pop(); // Remove method type from the stack
		(yyval.str) = (yyvsp[-1].str);
	}
#line 2761 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1275 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-2].str) + (yyvsp[0].str);
	}
#line 2769 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1282 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("struct");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype->as_struct())
		{
			current_depth++;
			const Struct* dstruct = dtype->as_struct();

			size_t num_fields = dstruct->get_num_fields();
			for(unsigned int i = 1; i <= num_fields; ++i)
			{
				// Reverse iteration
				const Field* field = dstruct->get_field(num_fields-i);
				// Add field types to stack such that the first is on top
				type_stack.push(TypeAndDepth(field->get_type(), current_depth));
			}
		}
		else
		{
			parser_error("Cannot use struct-composition for non-struct type '"
			             + format_type(dtype->get_type()) + "'.");
		}
	}
#line 2798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1307 "parser.ypp" /* yacc.c:1646  */
    {
		if(type_stack.top().type->as_struct())
		{
			current_depth--;
		}
		type_stack.pop(); // Remove method type from the stack
		(yyval.str) = (yyvsp[-1].str);
	}
#line 2811 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1321 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-2].str) + (yyvsp[0].str);
	}
#line 2819 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1325 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-2].str) + (yyvsp[0].str);
	}
#line 2827 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1332 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("array");

		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop();
		if(!dtype->as_array())
		{
			parser_error("Cannot use array-composition for non-array type '"
			             + format_type(dtype->get_type()) + "'.");
			(yyval.str) = "";
			break;
		}

		const ArrayType* array = dtype->as_array();
		if(!array->has_range()) // Simplest case
		{
			(yyval.str) = "";
			break;
		}

		// set to the obvious default value
		uint64_t min_array_elements = array->get_range().min.uinteger;
		(yyval.str) = string(min_array_elements, '\0');
	}
#line 2856 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1357 "parser.ypp" /* yacc.c:1646  */
    {
		if(!check_depth()) depth_error("array");

		const DistributedType* dtype = type_stack.top().type;
		if(dtype->as_array())
		{
			const ArrayType* array = dtype->as_array();

			// For arrays we're going to do something pretty hacky:
			//    For every element we had we are going to increment the depth,
			//    and after we finish the element_values production we will compare
			//    the current_depth to the depth of our original symbol to check
			//    if the array size is proper.
			type_stack.push(TypeAndDepth(array->get_element_type(), current_depth));
		}
		else
		{
			parser_error("Cannot use array-composition for non-array type '"
			             + format_type(dtype->get_type()) + "'.");
		}
	}
#line 2882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1379 "parser.ypp" /* yacc.c:1646  */
    {
		if(type_stack.top().type->as_array())
		{
			uint64_t actual_size = current_depth - type_stack.top().depth;
			const ArrayType* array = type_stack.top().type->as_array();
			if(array->has_range())
			{
				if(actual_size > array->get_range().max.uinteger)
				{
					parser_error("Too many elements in array value, maximum "
					             + to_string(array->get_range().max.uinteger) + ".");
				}
				else if(actual_size < array->get_range().min.uinteger)
				{
					parser_error("Too few elements in array value, minimum "
					             + to_string(array->get_range().min.uinteger) + ".");
				}
			}
			current_depth = type_stack.top().depth;
		}
		type_stack.pop(); // Remove array type from the stack
		(yyval.str) = (yyvsp[-1].str);
	}
#line 2910 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1407 "parser.ypp" /* yacc.c:1646  */
    {
		// We popped off the only element we added, so we're back to the array
		// Don't increment the depth; the array_expansion will add to
		// the current_depth depending on the number of elements it adds.
		const ArrayType* array = type_stack.top().type->as_array();
		type_stack.push(TypeAndDepth(array->get_element_type(), current_depth));
	}
#line 2922 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1415 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.str) = (yyvsp[-3].str) + (yyvsp[0].str);
	}
#line 2930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1422 "parser.ypp" /* yacc.c:1646  */
    {
		current_depth++;
		(yyval.str) = (yyvsp[0].str);
	}
#line 2939 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1427 "parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].u.uint32); // For arrays, we add 1 to the depth per element

		string base = number_value(dtype->get_type(), (yyvsp[-2].u.int64));

		string val;
		val.reserve(base.length() * (yyvsp[0].u.uint32));
		for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
		{
			val += base;
		}
		(yyval.str) = val;
	}
#line 2959 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1443 "parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].u.uint32); // For arrays, we add 1 to the depth per element

		string base = number_value(dtype->get_type(), (yyvsp[-2].u.uint64));

		string val;
		val.reserve(base.length() * (yyvsp[0].u.uint32));
		for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
		{
			val += base;
		}
		(yyval.str) = val;
	}
#line 2979 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1459 "parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].u.uint32); // For arrays, we add 1 to the depth per element

		string base = number_value(dtype->get_type(), (yyvsp[-2].u.real));

		string val;
		val.reserve(base.length() * (yyvsp[0].u.uint32));
		for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
		{
			val += base;
		}
		(yyval.str) = val;
	}
#line 2999 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1475 "parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].u.uint32); // For arrays, we add 1 to the depth per element

		if(dtype->get_type() == T_STRING)
		{
			if((yyvsp[-2].str).length() != dtype->get_size())
			{
				parser_error("Value for fixed-length string has incorrect length.");
			}

			string val;
			val.reserve((yyvsp[-2].str).length() * (yyvsp[0].u.uint32));
			for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
			{
				val += (yyvsp[-2].str);
			}
			(yyval.str) = val;
		}
		else if(dtype->get_type() == T_VARSTRING)
		{
			// TODO: Check for range limits
			// Prepend length tag
			sizetag_t length = (yyvsp[-2].str).length();
			string base = string((char*)&length, sizeof(sizetag_t)) + (yyvsp[-2].str);

			string val;
			val.reserve(base.length() * (yyvsp[0].u.uint32));
			for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
			{
				val += base;
			}
			(yyval.str) = val;
		}
		else
		{
			parser_error("Cannot use string value for non-string type '"
			             + format_type(dtype->get_type()) + "'.");

			string val;
			val.reserve((yyvsp[-2].str).length() * (yyvsp[0].u.uint32));
			for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
			{
				val += (yyvsp[-2].str);
			}
			(yyval.str) = val;
		}
	}
#line 3053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1525 "parser.ypp" /* yacc.c:1646  */
    {
		const DistributedType* dtype = type_stack.top().type;
		type_stack.pop(); // Pop that array element type
		current_depth += (yyvsp[0].u.uint32); // For arrays, we add 1 to the depth per element

		if(dtype->get_type() == T_BLOB)
		{
			if((yyvsp[-2].str).length() != dtype->get_size())
			{
				parser_error("Value for fixed-length blob has incorrect length.");
			}

			string val;
			val.reserve((yyvsp[-2].str).length() * (yyvsp[0].u.uint32));
			for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
			{
				val += (yyvsp[-2].str);
			}
			(yyval.str) = val;
		}
		else if(dtype->get_type() == T_VARBLOB)
		{
			// TODO: Check for range limits
			// Prepend length tag
			sizetag_t length = (yyvsp[-2].str).length();
			string base = string((char*)&length, sizeof(sizetag_t)) + (yyvsp[-2].str);

			string val;
			val.reserve(base.length() * (yyvsp[0].u.uint32));
			for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
			{
				val += base;
			}
			(yyval.str) = val;

		}
		else
		{
			parser_error("Cannot use hex value for non-blob type '"
			             + format_type(dtype->get_type()) + "'.");

			string val;
			val.reserve((yyvsp[-2].str).length() * (yyvsp[0].u.uint32));
			for(unsigned int i = 0; i < (yyvsp[0].u.uint32); ++i)
			{
				val += (yyvsp[-2].str);
			}
			(yyval.str) = val;
		}
	}
#line 3108 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1578 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_STRING; }
#line 3114 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1579 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_BLOB; }
#line 3120 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1583 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_CHAR; }
#line 3126 "parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1584 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_INT8; }
#line 3132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1585 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_INT16; }
#line 3138 "parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1586 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_INT32; }
#line 3144 "parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1587 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_INT64; }
#line 3150 "parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1588 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_UINT8; }
#line 3156 "parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1589 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_UINT16; }
#line 3162 "parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1590 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_UINT32; }
#line 3168 "parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1591 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_UINT64; }
#line 3174 "parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1592 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_FLOAT32; }
#line 3180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1593 "parser.ypp" /* yacc.c:1646  */
    { (yyval.u.type) = T_FLOAT64; }
#line 3186 "parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1598 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval.strings) = vector<string>();
	}
#line 3194 "parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1602 "parser.ypp" /* yacc.c:1646  */
    {
		if(!parsed_file->has_keyword((yyvsp[0].str)))
		{
			parser_error("Keyword '" + (yyvsp[0].str) + "' has not been declared.");
			break;
		}

		(yyvsp[-1].strings).push_back((yyvsp[0].str));
		(yyval.strings) = (yyvsp[-1].strings);
	}
#line 3209 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3213 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1618 "parser.ypp" /* yacc.c:1906  */
 /* Start helper function section */


bool check_depth()
{
	return (!type_stack.empty() && current_depth == type_stack.top().depth);
}

void depth_error(string what)
{
	if(type_stack.empty() || current_depth < type_stack.top().depth)
	{
		parser_error("Too many nested values while parsing value for " + what + ".");
	}
	else
	{
		parser_error("Too few nested values while parsing value for " + what + ".");	
	}
}

void depth_error(int depth, string what)
{
	if(current_depth > depth)
	{
		parser_error("Too few nested values before this " + what + " value.");
	}
	else
	{
		parser_error("Too many nested values before this " + what + " value.");
	}
}

string number_value(Type type, double &number)
{
	switch(type)
	{
		case T_FLOAT32:
		{
			float v = number;
			if(v == INFINITY || v == -INFINITY)
			{
				parser_error("Value is out of range for type 'float32'.");
			}

			return string((char*)&v, sizeof(float));
		}
		case T_FLOAT64:
		{
			return string((char*)&number, sizeof(double));
		}
		case T_INT8:
		case T_INT16:
		case T_INT32:
		case T_INT64:
		case T_CHAR:
		case T_UINT8:
		case T_UINT16:
		case T_UINT32:
		case T_UINT64:
		{
			parser_error("Cannot use floating-point value for integer datatype.");
			return string();
		}
		default:
		{
			parser_error("Cannot use floating-point value for non-numeric datatype.");
			return string();
		}
	}
}

string number_value(Type type, int64_t &number)
{
	switch(type)
	{
		case T_INT8:
		{
			if(INT8_MIN > number || number > INT8_MAX)
			{
				parser_error("Signed integer out of range for type 'int8'.");
			}

			int8_t v = number;
			return string((char*)&v, sizeof(int8_t));
		}
		case T_INT16:
		{
			if(INT16_MIN > number || number > INT16_MAX)
			{
				parser_error("Signed integer out of range for type 'int16'.");
			}

			uint16_t v = number;
			return string((char*)&v, sizeof(int16_t));
		}
		case T_INT32:
		{
			if(INT32_MIN > number || number > INT32_MAX)
			{
				parser_error("Signed integer out of range for type 'int32'.");
			}

			int32_t v = number;
			return string((char*)&v, sizeof(int32_t));
		}
		case T_INT64:
		{
			return string((char*)&number, sizeof(int64_t));
		}
		case T_CHAR:
		case T_UINT8:
		case T_UINT16:
		case T_UINT32:
		case T_UINT64:
		{
			if(number < 0)
			{
				parser_error("Can't use negative value for unsigned integer datatype.");
			}
			uint64_t v = number;
			return number_value(type, v);
		}
		case T_FLOAT32:
		case T_FLOAT64:
		{
			// Note: Expecting number to be converted to a double by value (ie. -1 becomes -1.0)
			double v = number;
			return number_value(type, v);
		}
		default:
		{
			parser_error("Cannot use signed integer value for non-numeric datatype.");
			return string();
		}
	}
}

string number_value(Type type, uint64_t &number)
{
	switch(type)
	{
		case T_CHAR:
		case T_UINT8:
		{
			if(number > UINT8_MAX)
			{
				parser_error("Unsigned integer out of range for type 'uint8'.");
			}

			uint8_t v = number;
			return string((char*)&v, sizeof(uint8_t));
		}
		case T_UINT16:
		{
			if(number > UINT16_MAX)
			{
				parser_error("Unsigned integer out of range for type 'uint16'.");
			}

			uint16_t v = number;
			return string((char*)&v, sizeof(uint16_t));
		}
		case T_UINT32:
		{
			if(number > UINT32_MAX)
			{
				parser_error("Unsigned integer out of range for type 'uint32'.");
			}

			uint32_t v = number;
			return string((char*)&v, sizeof(uint32_t));
		}
		case T_UINT64:
		{
			return string((char*)&number, sizeof(uint64_t));
		}
		case T_INT8:
		case T_INT16:
		case T_INT32:
		case T_INT64:
		{
			if(number > INT64_MAX)
			{
				parser_error("Unsigned integer out of range for signed integer datatype.");
			}
			int64_t v = number;
			return number_value(type, v);
		}
		case T_FLOAT32:
		case T_FLOAT64:
		{
			// Note: Expecting number to be converted to a double by value (ie. 3 becomes 3.0)
			double v = number;
			return number_value(type, v);
		}
		default:
		{
			parser_error("Cannot use unsigned integer value for non-numeric datatype.");
			return string();
		}
	}
}


} // close namespace dclass
